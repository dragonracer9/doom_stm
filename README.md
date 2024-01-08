# doom_stm

A simplistic port of DOOM to stm 32 l47 (using an STM nucleo development board). Runs on a proprietary shield supplied by ETH Zürich.

## Toolchain

Uses the STM CubeIDE and CUBE MX programs to compile and generate hardware specific code.

## Roadmap

- get basic syscall functions running ☑️
- see if doom runs as is? (doesnt, so i will have to fix that...)
- try sticking this on an RTOS (why not) ([threadX](https://github.com/azure-rtos/threadx)]
