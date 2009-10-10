all: sandbox.asm
	wla-65816 -vo sandbox.asm sandbox.obj
	wlalink -vr sandbox.link sandbox.smc

clean:
	rm *.obj *.smc
