#############################
# Auto-make file: default.mak
#############################

# Following variables should be updated to reflect you current project settings.
# PROJECT:      				Project name. Name of the final absolute/S19/library file,
#                       without path information  
PROJECT=MyProject

# SOURCE_FILES:					All C/C++/ASM files (without path)
SOURCE_FILES=datapage.c \
             Start12.c \
             main.c 
             
# ADD_OBJECTS:  				Additional object/library files to link with
ADD_OBJECTS=ansisi.lib

# INSTALLPATH: 	        Path where tools are installed (root installation 
#                       directory). If called from build.bat, INSTALLPATH 
#                       is through -D option.
#                       Remove comment below and adjust path if INSTALLPATH is not  
#                       set on make invocation line
#INSTALLPATH=C:\Freescale\CodeWarrior_HC12
# LINKFILE:    	        Linker parameter file to be used
LINKFILE=.\prm\project.prm	  
# MAKEFILE:    	        Name of this make file
MAKEFILE=default.mak 

# define here if you want to build a absolute file (abs) or a library (lib)
BUILD_TARGET_EXT=abs
#BUILD_TARGET_EXT=lib

#INCLUDEPATH:           Paths where application or system include files can be 
#                       found.
INCLUDEPATH="$(INSTALLPATH)\lib\hc12c\include"

#GENPATH:                Paths where application source and prm files can be 
#                         found
GENPATH=.\Sources;$(INSTALLPATH)\lib\hc12c\src;$(INSTALLPATH)\lib\hc12c\include;$(INSTALLPATH)\lib\hc12c\lib;

#OBJPATH:                Path where compiler and assembler will place object files 
OBJPATH=.\bin
#ABSPATH:                Path where linker will place executable file
ABSPATH=.\bin
#TEXTPATH:               Path where linker will place map file and compiler 
#                        disassembly listing file and dependency file. 
TEXTPATH=.\bin

# The name of the dependency list file. Here the compiler itself updates the 
# make file!
DEP_LIST_FILE = $(PROJECT).dep


#ENVOPTIONS:             Command line options to set environment variables.
ENVOPTIONS=-ENV"GENPATH=$(GENPATH)" -ENV"OBJPATH=$(OBJPATH)" \
  -ENV"ABSPATH=$(ABSPATH)" -ENV"TEXTPATH=$(TEXTPATH)"

# Here there are some special options to select the object file format for 
# compiler/assembler/linker
CC_OBJ_FORMAT=-F2
AA_OBJ_FORMAT=-F2
LL_OBJ_FORMAT=-Fe

# Compiler settings, C and C++ options.
# Short description about the options used (you may adapt this options to your 
# own need):
#  -Lasm:    Produce listing file
#  -Lm:      Generate dependency information
#  -LmCfg:   Configuration options for -Lm: m=write path of main file, i=write 
#            path of included files, u=update information
#  -D:       Add preprocessor define, here it defines the target derivative name
#  -WmsgFob: Option to configure the message output format. Here we changed the 
#            format so that the column number is written too
#  -C++f:    Use full C++ mode for C++ files
CC=$(INSTALLPATH)\prog\cHC12.exe
CCFLAGS_COMMON= $(CC_OBJ_FORMAT) -Lasm -Lm=$(DEP_LIST_FILE) -WmsgNu=abcet \
                -I$(INCLUDEPATH) -LmCfg=ilmu $(ENVOPTIONS)
CCFLAGS=$(CCFLAGS_COMMON)
CPPFLAGS= $(CCFLAGS_COMMON) -C++f

# Assembler settings
# Short description about the options used (you may adapt this options to your 
# own need):
AA=$(INSTALLPATH)\prog\aHC12.exe  $(AA_OBJ_FORMAT) -WmsgNu=abcet $(ENVOPTIONS)
AAFLAGS=

# linker settings
# Short description about the options used (you may adapt this options to your 
# own need):
#  -M:       Generate map file (overwrites the optional MAPFILE command in the 
#            linker parameter file
#  -O:       Name of the output file. Overwrites the optional one specified in the 
#            linker parameter file
#  -Add:     The list of object/library files specified here is linked to the 
#            application (together with the ones specified in the linker parameter 
#            file)
LL=$(INSTALLPATH)\prog\linker.exe
LLFLAGS=  -M -O$(PROJECT).abs -WmsgNu=abcet -Add($(ALL_OBJ_FILES) $(ADD_OBJECTS)) \
          $(LL_OBJ_FORMAT) $(ENVOPTIONS)

# burner settings, only used for S-Record, Intel HEX or binary output files
# Short description about the options used (you may adapt this options to your 
# own need):
#  OPENFILE: Creates/opens the destination file
#  format:   Format of the file, here it is motorola S-Record
#  origin:   Start address from where to copy, here begin of memory (address zero)
#  len:      Set to maximum, that is the whole application
#  busWidth: Set to one, thus no splitting between different eeproms
#  SENDBYTE: Starts generation of the output
BB=$(INSTALLPATH)\prog\burner.exe
BBFLAGS=   $(ENVOPTIONS) \
  OPENFILE "$(PROJECT).s19" \
  format = motorola \
  origin = 0x0000 \
  len = 0xffffffff \
  busWidth = 1 \
  SENDBYTE 1 "$(PROJECT).abs"

# libmaker settings, only used for libraries
# Short description about the options used (you may adapt this options to your 
# own need):
LM=$(INSTALLPATH)\prog\libmaker.exe
LMFLAGS= $(ENVOPTIONS) -NoPath -Cmd"$(ALL_OBJ_FILES) $(ADD_OBJECTS) = $(PROJECT).lib"

##################################################################################
# from here you don't need to adapt the automake file
##################################################################################

# build object file list with search and replace operation
CPP_OBJ_FILES = $(SOURCE_FILES:.cpp=.o)
CXX_OBJ_FILES = $(CPP_OBJ_FILES:.cxx=.o)
C_OBJ_FILES   = $(CXX_OBJ_FILES:.c=.o)
S_OBJ_FILES   = $(C_OBJ_FILES:.s=.o)
ALL_OBJ_FILES = $(S_OBJ_FILES:.asm=.o)

#####################################
# rules  
#####################################
# top target
all: $(PROJECT).$(BUILD_TARGET_EXT)
  echo *** $(PROJECT) is up to date. ***

# this targets enforces a rebuild:
# 1) delete the dependency info file (may contain outdated information)
# 2) call a second maker process to build the target again, with following options:
#    $(MAKEFILE):  Make file, which is this file
#     -Prod:        Project file with all other settings
#     -WmsgVrb:     Use verbose mode, so we know what is going on
#     -D:           Pass through macro variables we got from the invocation line 
#                   directly (INSTALLPATH)
#     -ViewMin:     Run as iconified application
#     -Mkall:       Make the target without checking for dependency dates
rebuild:
  -del $(DEP_LIST_FILE)
  -del $(TEXTPATH)\$(DEP_LIST_FILE)
  $(INSTALLPATH)\prog\maker.exe $(MAKEFILE) $(ENVOPTIONS) -WmsgVrb \
              -D(INSTALLPATH=$(INSTALLPATH)) -ViewMin -mkall
  echo "*** rebuild done ***"

$(PROJECT).abs: $(LINKFILE) $(MAKEFILE) $(ALL_OBJ_FILES) $(ADD_OBJECTS)
  $(LL) $(LLFLAGS) $(LINKFILE)
  $(BB) $(BBFLAGS) 

$(PROJECT).lib: $(MAKEFILE) $(ALL_OBJ_FILES) $(ADD_OBJECTS)
  $(LM) $(LMFLAGS)

# various rules how to build an object file from a source file
.c.o:
  $(CC) $(CCFLAGS) $*.c

.cpp.o:
  $(CC) $(CPPFLAGS) $*.cpp

.cxx.o:
  $(CC) $(CPPFLAGS) $*.cxx

.asm.o:
  $(AA) $(AAFLAGS) $*.asm

.s.o:
  $(AA) $(AAFLAGS) $*.s

#######################################################
#dependency section, generated/updated by the compiler
#######################################################

INCLUDE $(DEP_LIST_FILE)
