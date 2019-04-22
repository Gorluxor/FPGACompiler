# FPGACompiler

Short documentation about instruction set supported by the custom FPGA assembly
https://github.com/milanvidakovic/FPGAEmulator/blob/master/CPU.docx

To assembly the FPGA assembler code you can use pre-compiled "customasm" in the repository or you could compile one yourself from the source code.
For source code (and to build on other platforms) you can find it here (RUST langauge) https://github.com/milanvidakovic/FPGAcustomasm

To emulate the execution of the binary code you can use the FPGAEmulator.jar, full source code of the emulater can be foudn here : 
https://github.com/milanvidakovic/FPGAEmulator

How to run instructions in Linux (Tested on 16.04 LTS):

1) make
2) ./micko < testFile.mc
3) ./customasm -f binary -i instruction-set.txt -o outputfile.bin inputassembly.asm
4) java -jar FPGAEmulator.jar
5) load the .bin file 
