@echo off

@echo ********************************************************************************
@echo 			SDK BR17 Apps Soundbox  ...			
@echo ********************************************************************************
@echo %date%

@cd %~dp0

isd_download.exe -tonorflash -dev br17 -boot 0x2000 -div6 -wait 300 -format cfg -f uboot.bin sdram.app bt_cfg.bin fast_run.bin mp3\power_off.mp3 mp3\bt.mp3 mp3\music.mp3 mp3\linein.mp3 mp3\radio.mp3 mp3\pc.mp3 mp3\wait.mp3 mp3\connect.mp3 mp3\disconnect.mp3 mp3\ring.mp3 mp3\0.mp3 mp3\1.mp3 mp3\2.mp3 mp3\3.mp3 mp3\4.mp3 mp3\5.mp3 mp3\6.mp3 mp3\7.mp3 mp3\8.mp3 mp3\9.mp3 mp3\usb.mp3 mp3\sd.mp3 mp3\low_bat.mp3 mp3\max_vol.mp3 -key HJX_AC690X-5309.key

::-format cfg
:: -read flash_r.bin 0-2M

@if exist *.mp3 del *.mp3 
@if exist *.PIX del *.PIX
@if exist *.TAB del *.TAB
@if exist *.res del *.res
@if exist *.sty del *.sty
@if exist jl_690x.bin del jl_690x.bin
@if exist jl_cfg.bin del jl_cfg.bin

rename jl_isd.bin jl_690x.bin
bfumake.exe -fi jl_690x.bin -ld 0x0000 -rd 0x0000 -fo jl_690x.bfu

@rem rename jl_isd.bin jl_cfg.bin
@rem bfumake.exe -fi jl_cfg.bin -ld 0x0000 -rd 0x0000 -fo jl_690x.bfu
@rem copy /b jl_690x.bfu+jl_flash_cfg.bin  jl_690x.bfu

@if exist no_isd_file del jl_690x.bin jl_cfg.bin no_isd_file



