# doom_stm

A simplistic port of DOOM to stm 32 l47 (using an STM nucleo development board). Runs on a proprietary shield supplied by ETH Zürich.

## Toolchain

Uses the STM CubeIDE and CUBE MX programs to compile and generate hardware specific code.

## Roadmap

- basic button and matrix functionality ☑️
- get basic syscalls running ☑️
- see if doom runs as is? (doesnt, so i will have to fix that...) -> requires FATfs, not sure about the ipx stuff, will have to rewrite the serial drivers

- ([threadX](https://github.com/azure-rtos/threadx))
