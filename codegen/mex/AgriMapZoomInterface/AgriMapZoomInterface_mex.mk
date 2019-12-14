START_DIR = D:\27FBA~1.AGR

MATLAB_ROOT = F:\MATLAB~1
MAKEFILE = AgriMapZoomInterface_mex.mk

include AgriMapZoomInterface_mex.mki


SRC_FILES =  \
	AgriMapZoomInterface_mexutil.c \
	AgriMapZoomInterface_data.c \
	AgriMapZoomInterface_initialize.c \
	AgriMapZoomInterface_terminate.c \
	AgriMapZoomInterface.c \
	BL2XY_q.c \
	mpower.c \
	eml_int_forloop_overflow_check.c \
	error.c \
	sqrt.c \
	Preprocess.c \
	DPList.c \
	NormalizeDPList.c \
	judgeClockWise.c \
	flipud.c \
	Calculate_New_Indented_Boundary_Point.c \
	Judge_Intersect.c \
	CalculateLineCrossover.c \
	sort1.c \
	sortIdx.c \
	Calculate_Monolateral_Points.c \
	CalculateSina.c \
	Calculate_Effective_Point.c \
	Sort2.c \
	CalculateIntersection.c \
	indexShapeCheck.c \
	sortrows.c \
	sortLE.c \
	Calculate_Area.c \
	sum.c \
	Calculate_Map_Points.c \
	CalculateNewPoint.c \
	CalculateCosa.c \
	Reduce_Angle.c \
	XY2BL.c \
	_coder_AgriMapZoomInterface_info.c \
	_coder_AgriMapZoomInterface_api.c \
	_coder_AgriMapZoomInterface_mex.c \
	AgriMapZoomInterface_emxutil.c

MEX_FILE_NAME_WO_EXT = AgriMapZoomInterface_mex
MEX_FILE_NAME = $(MEX_FILE_NAME_WO_EXT).mexw64
TARGET = $(MEX_FILE_NAME)

SYS_LIBS = 


#
#====================================================================
# gmake makefile fragment for building MEX functions using LCC
# Copyright 2007-2012 The MathWorks, Inc.
#====================================================================
#
SHELL = cmd
OBJEXT = obj
CC = $(COMPILER)
LD = $(LINKER)
.SUFFIXES: .$(OBJEXT)

OBJLIST += $(SRC_FILES:.c=.$(OBJEXT))
MEXSTUB = $(MEX_FILE_NAME_WO_EXT)2.$(OBJEXT)
LCCSTUB = $(MEX_FILE_NAME_WO_EXT)_lccstub.$(OBJEXT)

target: $(TARGET)

ML_INCLUDES = -I"$(MATLAB_ROOT)\simulink\include"
ML_INCLUDES+= -I"$(MATLAB_ROOT)\toolbox\shared\simtargets"
SYS_INCLUDE = $(ML_INCLUDES)

LCC_ROOT = $(MATLAB_ROOT)\sys\lcc64\lcc64

# Additional includes

SYS_INCLUDE += -I"$(START_DIR)"
SYS_INCLUDE += -I"$(START_DIR)\codegen\mex\AgriMapZoomInterface"
SYS_INCLUDE += -I".\interface"
SYS_INCLUDE += -I"$(MATLAB_ROOT)\extern\include"
SYS_INCLUDE += -I"."

EML_LIBS = libemlrt.lib libcovrt.lib libut.lib libmwblas.lib libmwmathutil.lib
SYS_LIBS += $(EML_LIBS)

DIRECTIVES = $(MEX_FILE_NAME_WO_EXT)_mex.def

COMP_FLAGS = $(COMPFLAGS) -DMX_COMPAT_32
LINK_FLAGS0= $(subst $(MEXSTUB),$(LCCSTUB),$(LINKFLAGS))
LINK_FLAGS = $(filter-out "mexFunction.def", $(LINK_FLAGS0))


ifeq ($(EMC_CONFIG),optim)
  COMP_FLAGS += $(OPTIMFLAGS)
  LINK_FLAGS += $(LINKOPTIMFLAGS)
else
  COMP_FLAGS += $(DEBUGFLAGS)
  LINK_FLAGS += $(LINKDEBUGFLAGS)
endif
LINK_FLAGS += -o $(TARGET)
LINK_FLAGS += 

CFLAGS =  $(COMP_FLAGS) $(USER_INCLUDE) $(SYS_INCLUDE)

%.$(OBJEXT) : %.c
	$(CC) $(CFLAGS) "$<"

# Additional sources

%.$(OBJEXT) : $(START_DIR)/%.c
	$(CC) -Fo"$@" $(CFLAGS) "$<"

%.$(OBJEXT) : $(START_DIR)\codegen\mex\AgriMapZoomInterface/%.c
	$(CC) -Fo"$@" $(CFLAGS) "$<"

%.$(OBJEXT) : interface/%.c
	$(CC) -Fo"$@" $(CFLAGS) "$<"



$(LCCSTUB) : $(LCC_ROOT)\mex\lccstub.c
	$(CC) -Fo$(LCCSTUB) $(CFLAGS) "$<"

$(TARGET): $(OBJLIST) $(LCCSTUB) $(MAKEFILE) $(DIRECTIVES)
	$(LD) $(OBJLIST) $(LINK_FLAGS) $(LINKFLAGSPOST) $(SYS_LIBS) $(DIRECTIVES)
	@cmd /C "echo Build completed using compiler $(EMC_COMPILER)"

#====================================================================

