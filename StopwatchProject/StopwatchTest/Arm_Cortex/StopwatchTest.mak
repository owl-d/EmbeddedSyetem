
############# Target type (Debug/Release) ##################
############################################################
CPPCompileDebug=-g
CPPCompileRelease=-O2
LinkDebug=
LinkRelease=
BuildSet=Debug

ConfigurationCPPCompileSwitches=  -I . -I$(CIDF_ROOT)/arm_cortex  -I$(CIDF_ROOT)/arm_cortex/oxf -DUSE_C_LIBRARY=0 -D__TARGET_FPU_NONE -DSEMIHOSTED=1 -DEVALUATOR7T=1 -DADS_BUILD=1 -mcpu=cortex-m4 -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb $(CPPCompileDebug) -DARM_IDF $(INST_FLAGS) $(INCLUDE_PATH) $(INST_INCLUDES) 

################### Compilation flags ######################
############################################################
INCLUDE_QUALIFIER=-I

################### Commands definition #########################
#################################################################
LIB_CMD=arm-none-eabi-ar
LINK_CMD=arm-none-eabi-ld
LIB_FLAGS=
LINK_FLAGS=$(LinkDebug)   

############### Generated macros #################
##################################################

FLAGSFILE=
RULESFILE=
OMROOT="C:/Users/limdo/IBM/Rational/Rhapsody/7.5.3/Share"

CPP_EXT=.c
H_EXT=.h
OBJ_EXT=.o
EXE_EXT=.axf
LIB_EXT=.a

INSTRUMENTATION=None

TIME_MODEL=RealTime

TARGET_TYPE=Executable

TARGET_NAME=StopwatchTest

all : $(TARGET_NAME)$(EXE_EXT) StopwatchTest.mak

TARGET_MAIN=MainStopwatchTest

LIBS=

INCLUDE_PATH=

ADDITIONAL_OBJS=

OBJS= \
  Button.o \
  Timer.o \
  Display.o \
  PushSwitch.o \
  StopwatchPkg.o




######################## Predefined macros ############################
#######################################################################
$(OBJS) : $(FLAGSFILE) $(RULESFILE) $(INST_LIBS) $(OXF_LIBS)


INST_FLAGS=
INST_INCLUDES=
INST_LIBS=
OXF_LIBS=$(CIDF_ROOT)\arm_cortex\oxf\idf$(LIB_EXT)
SOCK_LIB=


################## Generated dependencies ########################
##################################################################






Button.o : Button.c Button.h    StopwatchPkg.h Timer.h 
	@echo Compiling Button.c
		 armcc -c $(ConfigurationCPPCompileSwitches)  -oButton.o Button.c



Timer.o : Timer.c Timer.h    StopwatchPkg.h Display.h 
	@echo Compiling Timer.c
		 armcc -c $(ConfigurationCPPCompileSwitches)  -oTimer.o Timer.c



Display.o : Display.c Display.h    StopwatchPkg.h 
	@echo Compiling Display.c
		 armcc -c $(ConfigurationCPPCompileSwitches)  -oDisplay.o Display.c



PushSwitch.o : PushSwitch.c PushSwitch.h    StopwatchPkg.h Button.h 
	@echo Compiling PushSwitch.c
		 armcc -c $(ConfigurationCPPCompileSwitches)  -oPushSwitch.o PushSwitch.c



StopwatchPkg.o : StopwatchPkg.c StopwatchPkg.h    Button.h Timer.h Display.h PushSwitch.h 
	@echo Compiling StopwatchPkg.c
		 armcc -c $(ConfigurationCPPCompileSwitches)  -oStopwatchPkg.o StopwatchPkg.c






$(TARGET_MAIN)$(OBJ_EXT) : $(TARGET_MAIN)$(CPP_EXT) $(OBJS) $(FLAGSFILE) $(RULESFILE)
    #@echo Compiling $(TARGET_MAIN)$(CPP_EXT)
	arm-none-eabi-gcc -c $(ConfigurationCPPCompileSwitches) -o $(TARGET_MAIN)$(OBJ_EXT) $(TARGET_MAIN)$(CPP_EXT)

########################## Linking instructions ###############################
###############################################################################
$(TARGET_NAME)$(EXE_EXT): $(OBJS) $(ADDITIONAL_OBJS) $(TARGET_MAIN)$(OBJ_EXT) StopwatchTest.mak
	@echo Linking $(TARGET_NAME)$(EXE_EXT)
	$(LINK_CMD)  $(TARGET_MAIN)$(OBJ_EXT) $(OBJS) $(ADDITIONAL_OBJS) \
	$(LIBS) \
	$(INST_LIBS) \
	$(OXF_LIBS) \
	$(SOCK_LIB) \
	$(LINK_FLAGS) -o $(TARGET_NAME)$(EXE_EXT)

$(TARGET_NAME)$(LIB_EXT) : $(OBJS) $(ADDITIONAL_OBJS) StopwatchTest.mak
	@echo Building library $@
	$(LIB_CMD) -rc $(LIB_FLAGS) $(TARGET_NAME)$(LIB_EXT) $(OBJS) $(ADDITIONAL_OBJS)
clean:
	@echo Cleanup
	if exist Button.o erase Button.o
	if exist Timer.o erase Timer.o
	if exist Display.o erase Display.o
	if exist PushSwitch.o erase PushSwitch.o
	if exist StopwatchPkg.o erase StopwatchPkg.o
	if exist *$(OBJ_EXT) erase *$(OBJ_EXT)
	if exist $(TARGET_NAME).pdb erase $(TARGET_NAME).pdb
	if exist $(TARGET_NAME)$(LIB_EXT) erase $(TARGET_NAME)$(LIB_EXT)
	if exist $(TARGET_NAME).ilk erase $(TARGET_NAME).ilk
	if exist $(TARGET_NAME)$(EXE_EXT) erase $(TARGET_NAME)$(EXE_EXT)
