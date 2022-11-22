
JL_TOOLS=../tools/pi32

CC = $(JL_TOOLS)/bin/clang.exe
LD = $(JL_TOOLS)/bin/pi32-ld.exe
AR = $(JL_TOOLS)/bin/pi32-ar.exe
LL = $(JL_TOOLS)/bin/lto-wrapper.exe

OBJCOPY=$(JL_TOOLS)/bin/llvm-objcopy.exe
OBJDUMP=$(JL_TOOLS)/bin/llvm-objdump.exe

SYS_INCLUDES = \
-I$(JL_TOOLS)/include  \
-I$(JL_TOOLS)/include/libc

AR_ARGS = \
-r -s

LD_ARGS = \
-L$(JL_TOOLS)/include/libc \
-o \

CC_ARGS = \
-target pi32 \
-integrated-as \
-fno-builtin \
-mllvm -pi32-memreg-opt \
-mllvm -pi32-mem-offset-adj-opt \
-mllvm -pi32-const-spill \
-mllvm -pi32-enable-jz \
-mllvm -pi32-tailcall-opt \
-mllvm -inline-threshold=5 \
-mllvm -pi32-enable-itblock=1 \
-flto


ll_opt1 =\
-L$(JL_TOOLS)/libc \
-o $(POST_BUILD_DIR)\$(PLATFORM).or32

ll_opt2 =\
--output-version-info $(POST_BUILD_DIR)/ver.bin \
-T./$(POST_BUILD_DIR)/ram.ld -M=./$(POST_BUILD_DIR)/map.txt
-M=./$(POST_BUILD_DIR)/map.txt

ll_opt3 =\
--plugin-opt=-pi32-memreg-opt \
--plugin-opt=-pi32-mem-offset-adj-opt \
--plugin-opt=-pi32-const-spill \
--plugin-opt=-pi32-enable-jz \
--plugin-opt=-pi32-tailcall-opt \
--plugin-opt=-inline-threshold=5 \
--plugin-opt=-pi32-enable-itblock=1

SYS_LIBS = \
$(JL_TOOLS)/lib/libc.a  \
$(JL_TOOLS)/lib/libcompiler-rt.a \


OUT_PATH :=./obj
OBJS = $(addprefix $(OUT_PATH)/,$(objs)) $(addprefix $(OUT_PATH)/,$(obj_bs)) $(addprefix $(OUT_PATH)/,$(obj_ls))

build: prebuild $(CC) $(objs) $(obj_bs) $(obj_ls) $(POST_BUILD_DIR)/sdram.app

all: build $(POST_BUILD_DIR)/jl_690x.bfu

$(POST_BUILD_DIR)/$(PLATFORM).or32: $(OBJS)
	@echo '***** Link $(POST_BUILD_DIR)/$(PLATFORM).or32 ...'
	@$(LL) $(ll_opt1) $(OBJS) $(ll_opt2) $(LIBS) $(ll_opt3) $(SYS_LIBS)


$(POST_BUILD_DIR)/sdram.app: $(POST_BUILD_DIR)/$(PLATFORM).or32
	@echo '***** Postbuild'
	@$(OBJCOPY) -O binary -j .text  $(POST_BUILD_DIR)/$(PLATFORM).or32  $(POST_BUILD_DIR)/$(PLATFORM).bin
	@$(OBJCOPY) -O binary -j .data  $(POST_BUILD_DIR)/$(PLATFORM).or32  $(POST_BUILD_DIR)/data.bin
	@$(OBJCOPY) -O binary -j .data1 $(POST_BUILD_DIR)/$(PLATFORM).or32  $(POST_BUILD_DIR)/data1.bin
	@$(OBJDUMP) -section-headers  $(POST_BUILD_DIR)/$(PLATFORM).or32
	@dd if=$(POST_BUILD_DIR)/$(PLATFORM).bin >$(POST_BUILD_DIR)/sdram.app
	@dd if=$(POST_BUILD_DIR)/data.bin >>$(POST_BUILD_DIR)/sdram.app
	@dd if=$(POST_BUILD_DIR)/data1.bin >>$(POST_BUILD_DIR)/sdram.app
	@echo '***** Create $(POST_BUILD_DIR)/sdram.app - ok'


%.o: %.c
	@echo 'Building file: $<'
	@mkdir -p $(OUT_PATH)/$(@D)
	@$(CC) $(CC_ARG) $(CC_ARGS) $(INCLUDES) $(SYS_INCLUDES) -c -o"$(OUT_PATH)/$@" "$<"


%.o: %.S
	@echo 'Building file: $<'
	@mkdir -p $(OUT_PATH)/$(@D)
	@$(CC) $(CC_ARG) $(CC_ARGS) $(INCLUDES) $(SYS_INCLUDES) -c -o"$(OUT_PATH)/$@" "$<"


$(CC): 
ifneq ($(CC), $(wildcard $(CC)))
	@echo 'Extract $(JL_TOOLS) ...'
	@unzip -q ../tools/pi32.zip -d $(JL_TOOLS:/pi32=)
endif


prebuild:
	@echo '***** Prebuild'
	@$(RM) $(POST_BUILD_DIR)/$(PLATFORM).or32 $(POST_BUILD_DIR)/sdram.app $(POST_BUILD_DIR)/$(PLATFORM).bin $(POST_BUILD_DIR)/data.bin $(POST_BUILD_DIR)/data1.bin $(POST_BUILD_DIR)/jl_690x.bin $(POST_BUILD_DIR)/jl_690x.bfu


clean:
	@$(RM) -r $(OUT_PATH) $(POST_BUILD_DIR)/$(PLATFORM).or32 $(POST_BUILD_DIR)/sdram.app $(POST_BUILD_DIR)/$(PLATFORM).bin $(POST_BUILD_DIR)/data.bin $(POST_BUILD_DIR)/data1.bin $(POST_BUILD_DIR)/jl_690x.bin $(POST_BUILD_DIR)/jl_690x.bfu


download: $(POST_BUILD_DIR)/jl_690x.bfu


$(POST_BUILD_DIR)/jl_690x.bin: $(POST_BUILD_DIR)/sdram.app
	@echo '***** Create Download files'
	@$(RM) $(POST_BUILD_DIR)/jl_690x.bfu
	@cd $(POST_BUILD_DIR);./isd_download.exe -tonorflash -dev br17 -boot 0x2000 -div6 -wait 300 -format cfg -f uboot.bin sdram.app bt_cfg.bin fast_run.bin $(addprefix $(MP3_PATH)\\,$(MP3_FILES)) -key HJX_AC690X-5309.key
	@echo '***** Create $(POST_BUILD_DIR)/jl_690x.bin - ok'


$(POST_BUILD_DIR)/jl_690x.bfu: $(POST_BUILD_DIR)/jl_690x.bin
	@cd $(POST_BUILD_DIR);./bfumake.exe -fi jl_690x.bin -ld 0x0000 -rd 0x0000 -fo jl_690x.bfu
	@echo '***** Create $(POST_BUILD_DIR)/jl_690x.bfu - ok'

