#
# Generated Makefile - do not edit!
#
# Edit the Makefile in the project folder instead (../Makefile). Each target
# has a -pre and a -post target defined where you can add customized code.
#
# This makefile implements configuration specific macros and targets.


# Include project Makefile
ifeq "${IGNORE_LOCAL}" "TRUE"
# do not include local makefile. User is passing all local related variables already
else
include Makefile
# Include makefile containing local settings
ifeq "$(wildcard nbproject/Makefile-local-default.mk)" "nbproject/Makefile-local-default.mk"
include nbproject/Makefile-local-default.mk
endif
endif

# Environment
MKDIR=gnumkdir -p
RM=rm -f 
MV=mv 
CP=cp 

# Macros
CND_CONF=default
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
IMAGE_TYPE=debug
OUTPUT_SUFFIX=elf
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=dist/${CND_CONF}/${IMAGE_TYPE}/EmbeddedSystems1.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
else
IMAGE_TYPE=production
OUTPUT_SUFFIX=hex
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=dist/${CND_CONF}/${IMAGE_TYPE}/EmbeddedSystems1.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
endif

ifeq ($(COMPARE_BUILD), true)
COMPARISON_BUILD=-mafrlcsj
else
COMPARISON_BUILD=
endif

# Object Directory
OBJECTDIR=build/${CND_CONF}/${IMAGE_TYPE}

# Distribution Directory
DISTDIR=dist/${CND_CONF}/${IMAGE_TYPE}

# Source Files Quoted if spaced
SOURCEFILES_QUOTED_IF_SPACED=../Aufgabe1Main.c ../edaPIC33ADC.c ../edaPIC33BlinkLed.c ../edaPIC33Hardware.c ../edaPIC33LCD.c ../edaPIC33OtherStuff.c ../edaPIC33OutputCompare.c ../edaPIC33PWM.c ../edaPIC33RingBuffer.c ../edaPIC33Setup.c ../edaPIC33SystemTime.c ../edaPIC33Timer.c

# Object Files Quoted if spaced
OBJECTFILES_QUOTED_IF_SPACED=${OBJECTDIR}/_ext/1472/Aufgabe1Main.o ${OBJECTDIR}/_ext/1472/edaPIC33ADC.o ${OBJECTDIR}/_ext/1472/edaPIC33BlinkLed.o ${OBJECTDIR}/_ext/1472/edaPIC33Hardware.o ${OBJECTDIR}/_ext/1472/edaPIC33LCD.o ${OBJECTDIR}/_ext/1472/edaPIC33OtherStuff.o ${OBJECTDIR}/_ext/1472/edaPIC33OutputCompare.o ${OBJECTDIR}/_ext/1472/edaPIC33PWM.o ${OBJECTDIR}/_ext/1472/edaPIC33RingBuffer.o ${OBJECTDIR}/_ext/1472/edaPIC33Setup.o ${OBJECTDIR}/_ext/1472/edaPIC33SystemTime.o ${OBJECTDIR}/_ext/1472/edaPIC33Timer.o
POSSIBLE_DEPFILES=${OBJECTDIR}/_ext/1472/Aufgabe1Main.o.d ${OBJECTDIR}/_ext/1472/edaPIC33ADC.o.d ${OBJECTDIR}/_ext/1472/edaPIC33BlinkLed.o.d ${OBJECTDIR}/_ext/1472/edaPIC33Hardware.o.d ${OBJECTDIR}/_ext/1472/edaPIC33LCD.o.d ${OBJECTDIR}/_ext/1472/edaPIC33OtherStuff.o.d ${OBJECTDIR}/_ext/1472/edaPIC33OutputCompare.o.d ${OBJECTDIR}/_ext/1472/edaPIC33PWM.o.d ${OBJECTDIR}/_ext/1472/edaPIC33RingBuffer.o.d ${OBJECTDIR}/_ext/1472/edaPIC33Setup.o.d ${OBJECTDIR}/_ext/1472/edaPIC33SystemTime.o.d ${OBJECTDIR}/_ext/1472/edaPIC33Timer.o.d

# Object Files
OBJECTFILES=${OBJECTDIR}/_ext/1472/Aufgabe1Main.o ${OBJECTDIR}/_ext/1472/edaPIC33ADC.o ${OBJECTDIR}/_ext/1472/edaPIC33BlinkLed.o ${OBJECTDIR}/_ext/1472/edaPIC33Hardware.o ${OBJECTDIR}/_ext/1472/edaPIC33LCD.o ${OBJECTDIR}/_ext/1472/edaPIC33OtherStuff.o ${OBJECTDIR}/_ext/1472/edaPIC33OutputCompare.o ${OBJECTDIR}/_ext/1472/edaPIC33PWM.o ${OBJECTDIR}/_ext/1472/edaPIC33RingBuffer.o ${OBJECTDIR}/_ext/1472/edaPIC33Setup.o ${OBJECTDIR}/_ext/1472/edaPIC33SystemTime.o ${OBJECTDIR}/_ext/1472/edaPIC33Timer.o

# Source Files
SOURCEFILES=../Aufgabe1Main.c ../edaPIC33ADC.c ../edaPIC33BlinkLed.c ../edaPIC33Hardware.c ../edaPIC33LCD.c ../edaPIC33OtherStuff.c ../edaPIC33OutputCompare.c ../edaPIC33PWM.c ../edaPIC33RingBuffer.c ../edaPIC33Setup.c ../edaPIC33SystemTime.c ../edaPIC33Timer.c


CFLAGS=
ASFLAGS=
LDLIBSOPTIONS=

############# Tool locations ##########################################
# If you copy a project from one host to another, the path where the  #
# compiler is installed may be different.                             #
# If you open this project with MPLAB X in the new host, this         #
# makefile will be regenerated and the paths will be corrected.       #
#######################################################################
# fixDeps replaces a bunch of sed/cat/printf statements that slow down the build
FIXDEPS=fixDeps

.build-conf:  ${BUILD_SUBPROJECTS}
ifneq ($(INFORMATION_MESSAGE), )
	@echo $(INFORMATION_MESSAGE)
endif
	${MAKE}  -f nbproject/Makefile-default.mk dist/${CND_CONF}/${IMAGE_TYPE}/EmbeddedSystems1.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}

MP_PROCESSOR_OPTION=33EP512MU810
MP_LINKER_FILE_OPTION=,--script=p33EP512MU810.gld
# ------------------------------------------------------------------------------------
# Rules for buildStep: compile
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
${OBJECTDIR}/_ext/1472/Aufgabe1Main.o: ../Aufgabe1Main.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1472" 
	@${RM} ${OBJECTDIR}/_ext/1472/Aufgabe1Main.o.d 
	@${RM} ${OBJECTDIR}/_ext/1472/Aufgabe1Main.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../Aufgabe1Main.c  -o ${OBJECTDIR}/_ext/1472/Aufgabe1Main.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1472/Aufgabe1Main.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -mno-eds-warn  -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off  
	@${FIXDEPS} "${OBJECTDIR}/_ext/1472/Aufgabe1Main.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1472/edaPIC33ADC.o: ../edaPIC33ADC.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1472" 
	@${RM} ${OBJECTDIR}/_ext/1472/edaPIC33ADC.o.d 
	@${RM} ${OBJECTDIR}/_ext/1472/edaPIC33ADC.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../edaPIC33ADC.c  -o ${OBJECTDIR}/_ext/1472/edaPIC33ADC.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1472/edaPIC33ADC.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -mno-eds-warn  -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off  
	@${FIXDEPS} "${OBJECTDIR}/_ext/1472/edaPIC33ADC.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1472/edaPIC33BlinkLed.o: ../edaPIC33BlinkLed.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1472" 
	@${RM} ${OBJECTDIR}/_ext/1472/edaPIC33BlinkLed.o.d 
	@${RM} ${OBJECTDIR}/_ext/1472/edaPIC33BlinkLed.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../edaPIC33BlinkLed.c  -o ${OBJECTDIR}/_ext/1472/edaPIC33BlinkLed.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1472/edaPIC33BlinkLed.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -mno-eds-warn  -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off  
	@${FIXDEPS} "${OBJECTDIR}/_ext/1472/edaPIC33BlinkLed.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1472/edaPIC33Hardware.o: ../edaPIC33Hardware.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1472" 
	@${RM} ${OBJECTDIR}/_ext/1472/edaPIC33Hardware.o.d 
	@${RM} ${OBJECTDIR}/_ext/1472/edaPIC33Hardware.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../edaPIC33Hardware.c  -o ${OBJECTDIR}/_ext/1472/edaPIC33Hardware.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1472/edaPIC33Hardware.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -mno-eds-warn  -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off  
	@${FIXDEPS} "${OBJECTDIR}/_ext/1472/edaPIC33Hardware.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1472/edaPIC33LCD.o: ../edaPIC33LCD.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1472" 
	@${RM} ${OBJECTDIR}/_ext/1472/edaPIC33LCD.o.d 
	@${RM} ${OBJECTDIR}/_ext/1472/edaPIC33LCD.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../edaPIC33LCD.c  -o ${OBJECTDIR}/_ext/1472/edaPIC33LCD.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1472/edaPIC33LCD.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -mno-eds-warn  -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off  
	@${FIXDEPS} "${OBJECTDIR}/_ext/1472/edaPIC33LCD.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1472/edaPIC33OtherStuff.o: ../edaPIC33OtherStuff.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1472" 
	@${RM} ${OBJECTDIR}/_ext/1472/edaPIC33OtherStuff.o.d 
	@${RM} ${OBJECTDIR}/_ext/1472/edaPIC33OtherStuff.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../edaPIC33OtherStuff.c  -o ${OBJECTDIR}/_ext/1472/edaPIC33OtherStuff.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1472/edaPIC33OtherStuff.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -mno-eds-warn  -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off  
	@${FIXDEPS} "${OBJECTDIR}/_ext/1472/edaPIC33OtherStuff.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1472/edaPIC33OutputCompare.o: ../edaPIC33OutputCompare.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1472" 
	@${RM} ${OBJECTDIR}/_ext/1472/edaPIC33OutputCompare.o.d 
	@${RM} ${OBJECTDIR}/_ext/1472/edaPIC33OutputCompare.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../edaPIC33OutputCompare.c  -o ${OBJECTDIR}/_ext/1472/edaPIC33OutputCompare.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1472/edaPIC33OutputCompare.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -mno-eds-warn  -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off  
	@${FIXDEPS} "${OBJECTDIR}/_ext/1472/edaPIC33OutputCompare.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1472/edaPIC33PWM.o: ../edaPIC33PWM.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1472" 
	@${RM} ${OBJECTDIR}/_ext/1472/edaPIC33PWM.o.d 
	@${RM} ${OBJECTDIR}/_ext/1472/edaPIC33PWM.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../edaPIC33PWM.c  -o ${OBJECTDIR}/_ext/1472/edaPIC33PWM.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1472/edaPIC33PWM.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -mno-eds-warn  -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off  
	@${FIXDEPS} "${OBJECTDIR}/_ext/1472/edaPIC33PWM.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1472/edaPIC33RingBuffer.o: ../edaPIC33RingBuffer.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1472" 
	@${RM} ${OBJECTDIR}/_ext/1472/edaPIC33RingBuffer.o.d 
	@${RM} ${OBJECTDIR}/_ext/1472/edaPIC33RingBuffer.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../edaPIC33RingBuffer.c  -o ${OBJECTDIR}/_ext/1472/edaPIC33RingBuffer.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1472/edaPIC33RingBuffer.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -mno-eds-warn  -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off  
	@${FIXDEPS} "${OBJECTDIR}/_ext/1472/edaPIC33RingBuffer.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1472/edaPIC33Setup.o: ../edaPIC33Setup.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1472" 
	@${RM} ${OBJECTDIR}/_ext/1472/edaPIC33Setup.o.d 
	@${RM} ${OBJECTDIR}/_ext/1472/edaPIC33Setup.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../edaPIC33Setup.c  -o ${OBJECTDIR}/_ext/1472/edaPIC33Setup.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1472/edaPIC33Setup.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -mno-eds-warn  -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off  
	@${FIXDEPS} "${OBJECTDIR}/_ext/1472/edaPIC33Setup.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1472/edaPIC33SystemTime.o: ../edaPIC33SystemTime.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1472" 
	@${RM} ${OBJECTDIR}/_ext/1472/edaPIC33SystemTime.o.d 
	@${RM} ${OBJECTDIR}/_ext/1472/edaPIC33SystemTime.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../edaPIC33SystemTime.c  -o ${OBJECTDIR}/_ext/1472/edaPIC33SystemTime.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1472/edaPIC33SystemTime.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -mno-eds-warn  -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off  
	@${FIXDEPS} "${OBJECTDIR}/_ext/1472/edaPIC33SystemTime.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1472/edaPIC33Timer.o: ../edaPIC33Timer.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1472" 
	@${RM} ${OBJECTDIR}/_ext/1472/edaPIC33Timer.o.d 
	@${RM} ${OBJECTDIR}/_ext/1472/edaPIC33Timer.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../edaPIC33Timer.c  -o ${OBJECTDIR}/_ext/1472/edaPIC33Timer.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1472/edaPIC33Timer.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -mno-eds-warn  -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off  
	@${FIXDEPS} "${OBJECTDIR}/_ext/1472/edaPIC33Timer.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
else
${OBJECTDIR}/_ext/1472/Aufgabe1Main.o: ../Aufgabe1Main.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1472" 
	@${RM} ${OBJECTDIR}/_ext/1472/Aufgabe1Main.o.d 
	@${RM} ${OBJECTDIR}/_ext/1472/Aufgabe1Main.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../Aufgabe1Main.c  -o ${OBJECTDIR}/_ext/1472/Aufgabe1Main.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1472/Aufgabe1Main.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off  
	@${FIXDEPS} "${OBJECTDIR}/_ext/1472/Aufgabe1Main.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1472/edaPIC33ADC.o: ../edaPIC33ADC.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1472" 
	@${RM} ${OBJECTDIR}/_ext/1472/edaPIC33ADC.o.d 
	@${RM} ${OBJECTDIR}/_ext/1472/edaPIC33ADC.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../edaPIC33ADC.c  -o ${OBJECTDIR}/_ext/1472/edaPIC33ADC.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1472/edaPIC33ADC.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off  
	@${FIXDEPS} "${OBJECTDIR}/_ext/1472/edaPIC33ADC.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1472/edaPIC33BlinkLed.o: ../edaPIC33BlinkLed.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1472" 
	@${RM} ${OBJECTDIR}/_ext/1472/edaPIC33BlinkLed.o.d 
	@${RM} ${OBJECTDIR}/_ext/1472/edaPIC33BlinkLed.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../edaPIC33BlinkLed.c  -o ${OBJECTDIR}/_ext/1472/edaPIC33BlinkLed.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1472/edaPIC33BlinkLed.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off  
	@${FIXDEPS} "${OBJECTDIR}/_ext/1472/edaPIC33BlinkLed.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1472/edaPIC33Hardware.o: ../edaPIC33Hardware.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1472" 
	@${RM} ${OBJECTDIR}/_ext/1472/edaPIC33Hardware.o.d 
	@${RM} ${OBJECTDIR}/_ext/1472/edaPIC33Hardware.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../edaPIC33Hardware.c  -o ${OBJECTDIR}/_ext/1472/edaPIC33Hardware.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1472/edaPIC33Hardware.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off  
	@${FIXDEPS} "${OBJECTDIR}/_ext/1472/edaPIC33Hardware.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1472/edaPIC33LCD.o: ../edaPIC33LCD.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1472" 
	@${RM} ${OBJECTDIR}/_ext/1472/edaPIC33LCD.o.d 
	@${RM} ${OBJECTDIR}/_ext/1472/edaPIC33LCD.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../edaPIC33LCD.c  -o ${OBJECTDIR}/_ext/1472/edaPIC33LCD.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1472/edaPIC33LCD.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off  
	@${FIXDEPS} "${OBJECTDIR}/_ext/1472/edaPIC33LCD.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1472/edaPIC33OtherStuff.o: ../edaPIC33OtherStuff.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1472" 
	@${RM} ${OBJECTDIR}/_ext/1472/edaPIC33OtherStuff.o.d 
	@${RM} ${OBJECTDIR}/_ext/1472/edaPIC33OtherStuff.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../edaPIC33OtherStuff.c  -o ${OBJECTDIR}/_ext/1472/edaPIC33OtherStuff.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1472/edaPIC33OtherStuff.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off  
	@${FIXDEPS} "${OBJECTDIR}/_ext/1472/edaPIC33OtherStuff.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1472/edaPIC33OutputCompare.o: ../edaPIC33OutputCompare.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1472" 
	@${RM} ${OBJECTDIR}/_ext/1472/edaPIC33OutputCompare.o.d 
	@${RM} ${OBJECTDIR}/_ext/1472/edaPIC33OutputCompare.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../edaPIC33OutputCompare.c  -o ${OBJECTDIR}/_ext/1472/edaPIC33OutputCompare.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1472/edaPIC33OutputCompare.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off  
	@${FIXDEPS} "${OBJECTDIR}/_ext/1472/edaPIC33OutputCompare.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1472/edaPIC33PWM.o: ../edaPIC33PWM.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1472" 
	@${RM} ${OBJECTDIR}/_ext/1472/edaPIC33PWM.o.d 
	@${RM} ${OBJECTDIR}/_ext/1472/edaPIC33PWM.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../edaPIC33PWM.c  -o ${OBJECTDIR}/_ext/1472/edaPIC33PWM.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1472/edaPIC33PWM.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off  
	@${FIXDEPS} "${OBJECTDIR}/_ext/1472/edaPIC33PWM.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1472/edaPIC33RingBuffer.o: ../edaPIC33RingBuffer.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1472" 
	@${RM} ${OBJECTDIR}/_ext/1472/edaPIC33RingBuffer.o.d 
	@${RM} ${OBJECTDIR}/_ext/1472/edaPIC33RingBuffer.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../edaPIC33RingBuffer.c  -o ${OBJECTDIR}/_ext/1472/edaPIC33RingBuffer.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1472/edaPIC33RingBuffer.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off  
	@${FIXDEPS} "${OBJECTDIR}/_ext/1472/edaPIC33RingBuffer.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1472/edaPIC33Setup.o: ../edaPIC33Setup.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1472" 
	@${RM} ${OBJECTDIR}/_ext/1472/edaPIC33Setup.o.d 
	@${RM} ${OBJECTDIR}/_ext/1472/edaPIC33Setup.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../edaPIC33Setup.c  -o ${OBJECTDIR}/_ext/1472/edaPIC33Setup.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1472/edaPIC33Setup.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off  
	@${FIXDEPS} "${OBJECTDIR}/_ext/1472/edaPIC33Setup.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1472/edaPIC33SystemTime.o: ../edaPIC33SystemTime.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1472" 
	@${RM} ${OBJECTDIR}/_ext/1472/edaPIC33SystemTime.o.d 
	@${RM} ${OBJECTDIR}/_ext/1472/edaPIC33SystemTime.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../edaPIC33SystemTime.c  -o ${OBJECTDIR}/_ext/1472/edaPIC33SystemTime.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1472/edaPIC33SystemTime.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off  
	@${FIXDEPS} "${OBJECTDIR}/_ext/1472/edaPIC33SystemTime.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1472/edaPIC33Timer.o: ../edaPIC33Timer.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1472" 
	@${RM} ${OBJECTDIR}/_ext/1472/edaPIC33Timer.o.d 
	@${RM} ${OBJECTDIR}/_ext/1472/edaPIC33Timer.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../edaPIC33Timer.c  -o ${OBJECTDIR}/_ext/1472/edaPIC33Timer.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1472/edaPIC33Timer.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off  
	@${FIXDEPS} "${OBJECTDIR}/_ext/1472/edaPIC33Timer.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: assemble
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: assemblePreproc
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: link
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
dist/${CND_CONF}/${IMAGE_TYPE}/EmbeddedSystems1.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk    
	@${MKDIR} dist/${CND_CONF}/${IMAGE_TYPE} 
	${MP_CC} $(MP_EXTRA_LD_PRE)  -o dist/${CND_CONF}/${IMAGE_TYPE}/EmbeddedSystems1.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}  ${OBJECTFILES_QUOTED_IF_SPACED}      -mcpu=$(MP_PROCESSOR_OPTION)        -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)   -mreserve=data@0x1000:0x101B -mreserve=data@0x101C:0x101D -mreserve=data@0x101E:0x101F -mreserve=data@0x1020:0x1021 -mreserve=data@0x1022:0x1023 -mreserve=data@0x1024:0x1027 -mreserve=data@0x1028:0x104F   -Wl,--local-stack,,--defsym=__MPLAB_BUILD=1,--defsym=__MPLAB_DEBUG=1,--defsym=__DEBUG=1,--defsym=__MPLAB_DEBUGGER_PK3=1,$(MP_LINKER_FILE_OPTION),--stack=16,--check-sections,--data-init,--pack-data,--handles,--isr,--no-gc-sections,--fill-upper=0,--stackguard=16,--no-force-link,--smart-io,-Map="${DISTDIR}/${PROJECTNAME}.${IMAGE_TYPE}.map",--report-mem,--memorysummary,dist/${CND_CONF}/${IMAGE_TYPE}/memoryfile.xml$(MP_EXTRA_LD_POST) 
	
else
dist/${CND_CONF}/${IMAGE_TYPE}/EmbeddedSystems1.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk   
	@${MKDIR} dist/${CND_CONF}/${IMAGE_TYPE} 
	${MP_CC} $(MP_EXTRA_LD_PRE)  -o dist/${CND_CONF}/${IMAGE_TYPE}/EmbeddedSystems1.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX}  ${OBJECTFILES_QUOTED_IF_SPACED}      -mcpu=$(MP_PROCESSOR_OPTION)        -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -Wl,--local-stack,,--defsym=__MPLAB_BUILD=1,$(MP_LINKER_FILE_OPTION),--stack=16,--check-sections,--data-init,--pack-data,--handles,--isr,--no-gc-sections,--fill-upper=0,--stackguard=16,--no-force-link,--smart-io,-Map="${DISTDIR}/${PROJECTNAME}.${IMAGE_TYPE}.map",--report-mem,--memorysummary,dist/${CND_CONF}/${IMAGE_TYPE}/memoryfile.xml$(MP_EXTRA_LD_POST) 
	${MP_CC_DIR}\\xc16-bin2hex dist/${CND_CONF}/${IMAGE_TYPE}/EmbeddedSystems1.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX} -a  -omf=elf  
	
endif


# Subprojects
.build-subprojects:


# Subprojects
.clean-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r build/default
	${RM} -r dist/default

# Enable dependency checking
.dep.inc: .depcheck-impl

DEPFILES=$(shell mplabwildcard ${POSSIBLE_DEPFILES})
ifneq (${DEPFILES},)
include ${DEPFILES}
endif
