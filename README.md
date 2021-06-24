Introduction
============
This folder contains models and source code used for benchmarking in the paper entitled *Hybrid Synchronous-Asynchronous Execution of Reconfigurable PLC Programs in Edge Computing* accepted by IEEE TII. This archive provides all information needed to recreate the performance evaluations presented in the paper including the following:

1. 4DIAC project, including all function blocks type definitions (*.fbt files). 
2. Function blocks type definitions modified for TCC just-in-time compiling.
3. Complete FORTE_TCC source code and build scripts (setup_posix.sh).
4. Excerpt of the JIT FB type management in HERE (async. mode only ).
5. Dependencies for compiling FORTE_TCC (Mini-XML and Tiny CC).


System Configuration
====================
The results were obtained on an embedded PLC hardware platform RevPi connect. Details are:

1.  Hardware environment : RevPi connect (https://revolution.kunbus.com/revpi-connect/)
2.  Engineering environment: 4DIAC 1.31
3.  Deployment profiles in 4DIAC:
      FORTE_LUAJIT +DynamicTypeLoad
      FORTE_TCC + HOLOBLOC (FB types location: \home\pi\fbtlib)
      HERE + HOLOBLOC (FB types location: \home\pi\fbtlib)
      FORTE_precompiled + HOLOBLOC

The original benchmarks are provided by Zeeshan E. Bhatti et al. at https://github.com/PRETgroup/PihaBenchmarks, thanks for all their hard work!