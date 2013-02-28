# =========================================================================
#     This makefile was generated by
#     Bakefile 0.2.9 (http://www.bakefile.org)
#     Do not modify, all changes will be overwritten!
# =========================================================================



# -------------------------------------------------------------------------
# These are configurable options:
# -------------------------------------------------------------------------

# C compiler 
CC = cl

# C++ compiler 
CXX = cl

# Standard flags for CC 
CFLAGS = 

# Standard flags for C++ 
CXXFLAGS = 

# Standard preprocessor flags (common for CC and CXX) 
CPPFLAGS = 

# Standard linker flags 
LDFLAGS = 

# Use debug build of wxWidgets (linked with debug CRT)? [0,1]
#   0 - Release
#   1 - Debug
WX_DEBUG = 1

# Version of the wx library to build against. 
WX_VERSION = 29

# The directory where wxWidgets library is installed 
WX_DIR = $(WXWIN)

# Architecture of the CPU for which to build the executables and libraries [X86,AMD64,IA64]
#   X86 - i386-compatible
#   AMD64 - AMD 64 bit
#   IA64 - Itanium 64 bit
TARGET_CPU = X86



# -------------------------------------------------------------------------
# Do not modify the rest of this file!
# -------------------------------------------------------------------------

### Variables: ###

COMPILER_PREFIX = vc
TFP_CXXFLAGS = /MD$(VAR_23) /DWIN32 /D_UNICODE $(__WXDEBUG_DEFINE_p) /D__WXMSW__ \
	/I$(WX_DIR)\lib\$(COMPILER_PREFIX)$(WXCPU)_lib\msw$(WXLIBPOSTFIX) \
	/I$(WX_DIR)\include $(VAR) $(VAR_22) $(p) /Fdtfp.pdb /D_WINDOWS \
	/I..\..\include /I..\..\src /GR /EHsc /Yu"wx/wxprec.h" /Fp"wxprec_tfp.pch" \
	$(CPPFLAGS) $(CXXFLAGS)
TFP_OBJECTS =  \
	tfp_dlgEd.obj \
	tfp_dlgEdFamily.obj \
	tfp_dlgEdIndividual.obj \
	tfp_dlgEdPersona.obj \
	tfp_dlgEdRole.obj \
	tfp_dlgEdSystem.obj \
	tfp_dlgNote.obj \
	tfp_dlgRecTableCtrl.obj \
	tfp_dlgSelect.obj \
	tfp_dlgSelIndividual.obj \
	tfp_fbDlg.obj \
	tfp_tfpApp.obj \
	tfp_tfpFrame.obj \
	tfp_tfpMemory.obj \
	tfp_tfpRdGed.obj \
	tfp_tfpVersion.obj \
	tfp_tfpWr.obj \
	tfp_tfpWrAdmin.obj \
	tfp_tfpWrChart.obj \
	tfp_tfpWrEvent.obj \
	tfp_tfpWrFamily.obj \
	tfp_tfpWrIndividual.obj \
	tfp_tfpWrName.obj \
	tfp_tfpWrNotes.obj \
	tfp_tfpWrReference.obj \
	tfp_webviewfshandler.obj \
	tfp_dummy.obj
TFP_RESOURCES =  \
	tfp_tfp.res
CALENDAR_CXXFLAGS = /MD$(VAR_23) /DWIN32 /D_UNICODE $(__WXDEBUG_DEFINE_p) \
	/D__WXMSW__ \
	/I$(WX_DIR)\lib\$(COMPILER_PREFIX)$(WXCPU)_lib\msw$(WXLIBPOSTFIX) \
	/I$(WX_DIR)\include $(VAR) $(VAR_22) $(p) /Fdcalendar$(WXLIBPOSTFIX).pdb \
	/I..\..\include\cal /I..\..\include /GR /EHsc /Yu"wx/wxprec.h" \
	/Fp"wxprec_calendar.pch" $(CPPFLAGS) $(CXXFLAGS)
CALENDAR_OBJECTS =  \
	calendar_calAstro.obj \
	calendar_calendar.obj \
	calendar_calFrench.obj \
	calendar_calGregorian.obj \
	calendar_calJulian.obj \
	calendar_calMath.obj \
	calendar_calParse.obj \
	calendar_calRecord.obj \
	calendar_dummy.obj
TESTS_CXXFLAGS = /MD$(VAR_23) /DWIN32 /D_UNICODE $(__WXDEBUG_DEFINE_p) \
	/D__WXMSW__ \
	/I$(WX_DIR)\lib\$(COMPILER_PREFIX)$(WXCPU)_lib\msw$(WXLIBPOSTFIX) \
	/I$(WX_DIR)\include $(VAR) $(VAR_22) $(p) /Fdtests.pdb /D_CONSOLE \
	/I..\..\include /I..\..\tests /I$(CPPUNIT)\include /GR /EHsc /Yu"testprec.h" \
	/Fp"wxprec_tests.pch" $(CPPFLAGS) $(CXXFLAGS)
TESTS_OBJECTS =  \
	tests_dummy.obj \
	tests_test.obj \
	tests_testCalendar.obj \
	tests_testDatabase.obj
CALCALC_CXXFLAGS = /MD$(VAR_23) /DWIN32 /D_UNICODE $(__WXDEBUG_DEFINE_p) \
	/D__WXMSW__ \
	/I$(WX_DIR)\lib\$(COMPILER_PREFIX)$(WXCPU)_lib\msw$(WXLIBPOSTFIX) \
	/I$(WX_DIR)\include $(VAR) $(VAR_22) $(p) /Fdcalcalc.pdb /D_CONSOLE \
	/I..\..\include /GR /EHsc $(CPPFLAGS) $(CXXFLAGS)
CALCALC_OBJECTS =  \
	calcalc_calCalc.obj
FILE2CPP_CXXFLAGS = /MD$(VAR_23) /DWIN32 /D_UNICODE $(__WXDEBUG_DEFINE_p) \
	/D__WXMSW__ \
	/I$(WX_DIR)\lib\$(COMPILER_PREFIX)$(WXCPU)_lib\msw$(WXLIBPOSTFIX) \
	/I$(WX_DIR)\include $(VAR) $(VAR_22) $(p) /Fdfile2cpp.pdb /D_CONSOLE /GR /EHsc \
	$(CPPFLAGS) $(CXXFLAGS)
FILE2CPP_OBJECTS =  \
	file2cpp_fcMain.obj
DOCCORE_CXXFLAGS = /MD$(VAR_23) /DWIN32 /D_UNICODE $(__WXDEBUG_DEFINE_p) \
	/D__WXMSW__ \
	/I$(WX_DIR)\lib\$(COMPILER_PREFIX)$(WXCPU)_lib\msw$(WXLIBPOSTFIX) \
	/I$(WX_DIR)\include $(VAR) $(VAR_22) $(p) /Fddoccore.pdb /D_CONSOLE \
	/I..\..\include /GR /EHsc $(CPPFLAGS) $(CXXFLAGS)
DOCCORE_OBJECTS =  \
	doccore_dcMain.obj
WXSQLITE3_CFLAGS = /MD$(VAR_23) /DWIN32 /D_UNICODE $(__WXDEBUG_DEFINE_p) \
	/D__WXMSW__ \
	/I$(WX_DIR)\lib\$(COMPILER_PREFIX)$(WXCPU)_lib\msw$(WXLIBPOSTFIX) \
	/I$(WX_DIR)\include $(VAR) $(VAR_22) $(p) /Fdwxsqlite3$(WXLIBPOSTFIX).pdb \
	/DSQLITE_ENABLE_RTREE /I..\..\include $(CPPFLAGS) $(CFLAGS)
WXSQLITE3_CXXFLAGS = /MD$(VAR_23) /DWIN32 /D_UNICODE $(__WXDEBUG_DEFINE_p) \
	/D__WXMSW__ \
	/I$(WX_DIR)\lib\$(COMPILER_PREFIX)$(WXCPU)_lib\msw$(WXLIBPOSTFIX) \
	/I$(WX_DIR)\include $(VAR) $(VAR_22) $(p) /Fdwxsqlite3$(WXLIBPOSTFIX).pdb \
	/DSQLITE_ENABLE_RTREE /I..\..\include /GR /EHsc $(CPPFLAGS) $(CXXFLAGS)
WXSQLITE3_OBJECTS =  \
	wxsqlite3_wxsqlite3.obj \
	wxsqlite3_sqlite3.obj
REC_CXXFLAGS = /MD$(VAR_23) /DWIN32 /D_UNICODE $(__WXDEBUG_DEFINE_p) /D__WXMSW__ \
	/I$(WX_DIR)\lib\$(COMPILER_PREFIX)$(WXCPU)_lib\msw$(WXLIBPOSTFIX) \
	/I$(WX_DIR)\include $(VAR) $(VAR_22) $(p) /Fdrec$(WXLIBPOSTFIX).pdb \
	/I..\..\include\rec /I..\..\include /GR /EHsc /Yu"wx/wxprec.h" \
	/Fp"wxprec_rec.pch" $(CPPFLAGS) $(CXXFLAGS)
REC_OBJECTS =  \
	rec_recContact.obj \
	rec_recDatabase.obj \
	rec_recDate.obj \
	rec_recEvent.obj \
	rec_recFilterEvent.obj \
	rec_recGedParse.obj \
	rec_recIndividual.obj \
	rec_recLink.obj \
	rec_recName.obj \
	rec_recPersona.obj \
	rec_recPlace.obj \
	rec_recReference.obj \
	rec_recRelationship.obj \
	rec_recSource.obj \
	rec_recSystem.obj \
	rec_recUser.obj \
	rec_recVersion.obj \
	rec_dummy.obj
RECCL_CXXFLAGS = /MD$(VAR_23) /DWIN32 /D_UNICODE $(__WXDEBUG_DEFINE_p) \
	/D__WXMSW__ \
	/I$(WX_DIR)\lib\$(COMPILER_PREFIX)$(WXCPU)_lib\msw$(WXLIBPOSTFIX) \
	/I$(WX_DIR)\include $(VAR) $(VAR_22) $(p) /Fdreccl$(WXLIBPOSTFIX).pdb \
	/I..\..\include\rec /I..\..\include /GR /EHsc $(CPPFLAGS) $(CXXFLAGS)
RECCL_OBJECTS =  \
	reccl_reccl.obj
RECGUI_CXXFLAGS = /MD$(VAR_23) /DWIN32 /D_UNICODE $(__WXDEBUG_DEFINE_p) \
	/D__WXMSW__ \
	/I$(WX_DIR)\lib\$(COMPILER_PREFIX)$(WXCPU)_lib\msw$(WXLIBPOSTFIX) \
	/I$(WX_DIR)\include $(VAR) $(VAR_22) $(p) /Fdrecgui$(WXLIBPOSTFIX).pdb \
	/I..\..\include\rec /I..\..\include\rg /I..\..\include /GR /EHsc $(CPPFLAGS) \
	$(CXXFLAGS)
RECGUI_OBJECTS =  \
	recgui_recgui.obj \
	recgui_fbRgDialog.obj \
	recgui_rgCompareEvent.obj \
	recgui_rgCrName.obj \
	recgui_rgDialogs.obj \
	recgui_rgEdContact.obj \
	recgui_rgEdDate.obj \
	recgui_rgEdEvent.obj \
	recgui_rgEdEventType.obj \
	recgui_rgEdEvidEvent.obj \
	recgui_rgEdName.obj \
	recgui_rgEdNamePart.obj \
	recgui_rgEdPerIndEvent.obj \
	recgui_rgEdPlace.obj \
	recgui_rgEdReference.obj \
	recgui_rgEdRelationship.obj \
	recgui_rgEdResearcher.obj \
	recgui_rgEdRole.obj \
	recgui_rgSelect.obj \
	recgui_rgSelIndEvent.obj \
	recgui_rgTableCtrl.obj

### Conditionally set variables: ###

!if "$(WX_DEBUG)" == "1"
WX3RDPARTYLIBPOSTFIX = d
!endif
!if "$(TARGET_CPU)" == "AMD64"
WXMACHINE_FLAG = /MACHINE:AMD64
!endif
!if "$(TARGET_CPU)" == "IA64"
WXMACHINE_FLAG = /MACHINE:IA64
!endif
!if "$(WX_DEBUG)" == "1"
__WXDEBUG_DEFINE_p_1 = /d __WXDEBUG__
!endif
!if "$(WX_DEBUG)" == "0"
______tfp__DEBUGINFO_6_p_1 = 
!endif
!if "$(WX_DEBUG)" == "1"
______tfp__DEBUGINFO_6_p_1 = /d _DEBUG
!endif
!if "$(WX_DEBUG)" == "0"
____tfp__DEBUGINFO_9 = 
!endif
!if "$(WX_DEBUG)" == "1"
____tfp__DEBUGINFO_9 = $(VAR_15)
!endif
!if "$(WX_DEBUG)" == "0"
____tests__DEBUGINFO_34 = 
!endif
!if "$(WX_DEBUG)" == "1"
____tests__DEBUGINFO_34 = $(VAR_15)
!endif
!if "$(WX_DEBUG)" == "0"
____WX_DEBUG_39_p = cppunit.lib
!endif
!if "$(WX_DEBUG)" == "1"
____WX_DEBUG_39_p = cppunitd.lib
!endif
!if "$(WX_DEBUG)" == "0"
____calcalc__DEBUGINFO_49 = 
!endif
!if "$(WX_DEBUG)" == "1"
____calcalc__DEBUGINFO_49 = $(VAR_15)
!endif
!if "$(WX_DEBUG)" == "0"
____file2cpp__DEBUGINFO_62 = 
!endif
!if "$(WX_DEBUG)" == "1"
____file2cpp__DEBUGINFO_62 = $(VAR_15)
!endif
!if "$(WX_DEBUG)" == "0"
____doccore__DEBUGINFO_75 = 
!endif
!if "$(WX_DEBUG)" == "1"
____doccore__DEBUGINFO_75 = $(VAR_15)
!endif
!if "$(WX_DEBUG)" == "0"
VAR_13 = 
!endif
!if "$(WX_DEBUG)" == "1"
VAR_13 = /DEBUG
!endif
!if "$(WX_DEBUG)" == "0"
VAR_15 = /opt:ref /opt:icf
!endif
!if "$(WX_DEBUG)" == "1"
VAR_15 = 
!endif
!if "$(WX_DEBUG)" == "1"
__WXDEBUG_DEFINE_p = /D__WXDEBUG__
!endif
!if "$(TARGET_CPU)" == "AMD64"
WXCPU = _x64
!endif
!if "$(TARGET_CPU)" == "IA64"
WXCPU = _ia64
!endif
!if "$(WX_DEBUG)" == "0"
WXLIBPOSTFIX = u
!endif
!if "$(WX_DEBUG)" == "1"
WXLIBPOSTFIX = ud
!endif
!if "$(WX_DEBUG)" == "0"
VAR = /O2
!endif
!if "$(WX_DEBUG)" == "1"
VAR = /Od
!endif
!if "$(WX_DEBUG)" == "0"
VAR_22 = 
!endif
!if "$(WX_DEBUG)" == "1"
VAR_22 = /Zi
!endif
!if "$(WX_DEBUG)" == "0"
p = 
!endif
!if "$(WX_DEBUG)" == "1"
p = /D_DEBUG
!endif
!if "$(WX_DEBUG)" == "0"
VAR_23 = 
!endif
!if "$(WX_DEBUG)" == "1"
VAR_23 = d
!endif


### Targets: ###

all: test_for_selected_wxbuild tfp.exe calendar$(WXLIBPOSTFIX).lib tests.exe calcalc.exe file2cpp.exe doccore.exe wxsqlite3$(WXLIBPOSTFIX).lib rec$(WXLIBPOSTFIX).lib reccl$(WXLIBPOSTFIX).lib recgui$(WXLIBPOSTFIX).lib

clean: 
	-if exist .\*.obj del .\*.obj
	-if exist .\*.res del .\*.res
	-if exist .\*.pch del .\*.pch
	-if exist tfp.exe del tfp.exe
	-if exist tfp.ilk del tfp.ilk
	-if exist tfp.pdb del tfp.pdb
	-if exist calendar$(WXLIBPOSTFIX).lib del calendar$(WXLIBPOSTFIX).lib
	-if exist tests.exe del tests.exe
	-if exist tests.ilk del tests.ilk
	-if exist tests.pdb del tests.pdb
	-if exist calcalc.exe del calcalc.exe
	-if exist calcalc.ilk del calcalc.ilk
	-if exist calcalc.pdb del calcalc.pdb
	-if exist file2cpp.exe del file2cpp.exe
	-if exist file2cpp.ilk del file2cpp.ilk
	-if exist file2cpp.pdb del file2cpp.pdb
	-if exist doccore.exe del doccore.exe
	-if exist doccore.ilk del doccore.ilk
	-if exist doccore.pdb del doccore.pdb
	-if exist wxsqlite3$(WXLIBPOSTFIX).lib del wxsqlite3$(WXLIBPOSTFIX).lib
	-if exist rec$(WXLIBPOSTFIX).lib del rec$(WXLIBPOSTFIX).lib
	-if exist reccl$(WXLIBPOSTFIX).lib del reccl$(WXLIBPOSTFIX).lib
	-if exist recgui$(WXLIBPOSTFIX).lib del recgui$(WXLIBPOSTFIX).lib

test_for_selected_wxbuild: 
	@if not exist $(WX_DIR)\lib\$(COMPILER_PREFIX)$(WXCPU)_lib\msw$(WXLIBPOSTFIX)\wx\setup.h \
	echo ----------------------------------------------------------------------------
	@if not exist $(WX_DIR)\lib\$(COMPILER_PREFIX)$(WXCPU)_lib\msw$(WXLIBPOSTFIX)\wx\setup.h \
	echo The selected wxWidgets build is not available!
	@if not exist $(WX_DIR)\lib\$(COMPILER_PREFIX)$(WXCPU)_lib\msw$(WXLIBPOSTFIX)\wx\setup.h \
	echo Please use the options prefixed with WX_ to select another wxWidgets build.
	@if not exist $(WX_DIR)\lib\$(COMPILER_PREFIX)$(WXCPU)_lib\msw$(WXLIBPOSTFIX)\wx\setup.h \
	echo ----------------------------------------------------------------------------
	@if not exist $(WX_DIR)\lib\$(COMPILER_PREFIX)$(WXCPU)_lib\msw$(WXLIBPOSTFIX)\wx\setup.h \
	exit 1

tfp.exe: tfp_dummy.obj  $(TFP_OBJECTS) tfp_tfp.res wxsqlite3$(WXLIBPOSTFIX).lib rec$(WXLIBPOSTFIX).lib recgui$(WXLIBPOSTFIX).lib calendar$(WXLIBPOSTFIX).lib
	link /NOLOGO /OUT:$@  /LIBPATH:$(WX_DIR)\lib\$(COMPILER_PREFIX)$(WXCPU)_lib $(WXMACHINE_FLAG) $(VAR_13) /pdb:"tfp.pdb" $(____tfp__DEBUGINFO_9) /SUBSYSTEM:WINDOWS $(LDFLAGS) @<<
	$(TFP_OBJECTS) $(TFP_RESOURCES)  wxsqlite3$(WXLIBPOSTFIX).lib rec$(WXLIBPOSTFIX).lib recgui$(WXLIBPOSTFIX).lib calendar$(WXLIBPOSTFIX).lib wxmsw$(WX_VERSION)$(WXLIBPOSTFIX)_webview.lib wxmsw$(WX_VERSION)$(WXLIBPOSTFIX)_html.lib wxmsw$(WX_VERSION)$(WXLIBPOSTFIX)_adv.lib wxmsw$(WX_VERSION)$(WXLIBPOSTFIX)_core.lib wxbase$(WX_VERSION)$(WXLIBPOSTFIX).lib wxtiff$(WX3RDPARTYLIBPOSTFIX).lib wxjpeg$(WX3RDPARTYLIBPOSTFIX).lib wxpng$(WX3RDPARTYLIBPOSTFIX).lib wxzlib$(WX3RDPARTYLIBPOSTFIX).lib wxregex$(WXLIBPOSTFIX).lib wxexpat$(WX3RDPARTYLIBPOSTFIX).lib kernel32.lib user32.lib gdi32.lib comdlg32.lib winspool.lib winmm.lib shell32.lib comctl32.lib ole32.lib oleaut32.lib uuid.lib rpcrt4.lib advapi32.lib wsock32.lib oleacc.lib
<<

calendar$(WXLIBPOSTFIX).lib: calendar_dummy.obj  $(CALENDAR_OBJECTS)
	if exist $@ del $@
	link /LIB /NOLOGO /OUT:$@ @<<
	$(CALENDAR_OBJECTS)
<<

tests.exe: tests_dummy.obj  $(TESTS_OBJECTS) calendar$(WXLIBPOSTFIX).lib wxsqlite3$(WXLIBPOSTFIX).lib reccl$(WXLIBPOSTFIX).lib rec$(WXLIBPOSTFIX).lib
	link /NOLOGO /OUT:$@  /LIBPATH:$(WX_DIR)\lib\$(COMPILER_PREFIX)$(WXCPU)_lib $(WXMACHINE_FLAG) $(VAR_13) /pdb:"tests.pdb" $(____tests__DEBUGINFO_34) /SUBSYSTEM:CONSOLE /LIBPATH:$(CPPUNIT)\lib $(LDFLAGS) @<<
	$(TESTS_OBJECTS)   calendar$(WXLIBPOSTFIX).lib wxsqlite3$(WXLIBPOSTFIX).lib reccl$(WXLIBPOSTFIX).lib rec$(WXLIBPOSTFIX).lib $(____WX_DEBUG_39_p) wxmsw$(WX_VERSION)$(WXLIBPOSTFIX)_core.lib wxbase$(WX_VERSION)$(WXLIBPOSTFIX).lib wxbase$(WX_VERSION)$(WXLIBPOSTFIX)_net.lib wxtiff$(WX3RDPARTYLIBPOSTFIX).lib wxjpeg$(WX3RDPARTYLIBPOSTFIX).lib wxpng$(WX3RDPARTYLIBPOSTFIX).lib wxzlib$(WX3RDPARTYLIBPOSTFIX).lib wxregex$(WXLIBPOSTFIX).lib wxexpat$(WX3RDPARTYLIBPOSTFIX).lib kernel32.lib user32.lib gdi32.lib comdlg32.lib winspool.lib winmm.lib shell32.lib comctl32.lib ole32.lib oleaut32.lib uuid.lib rpcrt4.lib advapi32.lib wsock32.lib oleacc.lib
<<

calcalc.exe: $(CALCALC_OBJECTS) calendar$(WXLIBPOSTFIX).lib
	link /NOLOGO /OUT:$@  /LIBPATH:$(WX_DIR)\lib\$(COMPILER_PREFIX)$(WXCPU)_lib $(WXMACHINE_FLAG) $(VAR_13) /pdb:"calcalc.pdb" $(____calcalc__DEBUGINFO_49) /SUBSYSTEM:CONSOLE $(LDFLAGS) @<<
	$(CALCALC_OBJECTS)   calendar$(WXLIBPOSTFIX).lib wxbase$(WX_VERSION)$(WXLIBPOSTFIX).lib wxtiff$(WX3RDPARTYLIBPOSTFIX).lib wxjpeg$(WX3RDPARTYLIBPOSTFIX).lib wxpng$(WX3RDPARTYLIBPOSTFIX).lib wxzlib$(WX3RDPARTYLIBPOSTFIX).lib wxregex$(WXLIBPOSTFIX).lib wxexpat$(WX3RDPARTYLIBPOSTFIX).lib kernel32.lib user32.lib gdi32.lib comdlg32.lib winspool.lib winmm.lib shell32.lib comctl32.lib ole32.lib oleaut32.lib uuid.lib rpcrt4.lib advapi32.lib wsock32.lib oleacc.lib
<<

file2cpp.exe: $(FILE2CPP_OBJECTS)
	link /NOLOGO /OUT:$@  /LIBPATH:$(WX_DIR)\lib\$(COMPILER_PREFIX)$(WXCPU)_lib $(WXMACHINE_FLAG) $(VAR_13) /pdb:"file2cpp.pdb" $(____file2cpp__DEBUGINFO_62) /SUBSYSTEM:CONSOLE $(LDFLAGS) @<<
	$(FILE2CPP_OBJECTS)   wxbase$(WX_VERSION)$(WXLIBPOSTFIX).lib wxtiff$(WX3RDPARTYLIBPOSTFIX).lib wxjpeg$(WX3RDPARTYLIBPOSTFIX).lib wxpng$(WX3RDPARTYLIBPOSTFIX).lib wxzlib$(WX3RDPARTYLIBPOSTFIX).lib wxregex$(WXLIBPOSTFIX).lib wxexpat$(WX3RDPARTYLIBPOSTFIX).lib kernel32.lib user32.lib gdi32.lib comdlg32.lib winspool.lib winmm.lib shell32.lib comctl32.lib ole32.lib oleaut32.lib uuid.lib rpcrt4.lib advapi32.lib wsock32.lib oleacc.lib
<<

doccore.exe: $(DOCCORE_OBJECTS) calendar$(WXLIBPOSTFIX).lib wxsqlite3$(WXLIBPOSTFIX).lib rec$(WXLIBPOSTFIX).lib reccl$(WXLIBPOSTFIX).lib
	link /NOLOGO /OUT:$@  /LIBPATH:$(WX_DIR)\lib\$(COMPILER_PREFIX)$(WXCPU)_lib $(WXMACHINE_FLAG) $(VAR_13) /pdb:"doccore.pdb" $(____doccore__DEBUGINFO_75) /SUBSYSTEM:CONSOLE $(LDFLAGS) @<<
	$(DOCCORE_OBJECTS)   calendar$(WXLIBPOSTFIX).lib wxsqlite3$(WXLIBPOSTFIX).lib rec$(WXLIBPOSTFIX).lib reccl$(WXLIBPOSTFIX).lib wxbase$(WX_VERSION)$(WXLIBPOSTFIX).lib wxtiff$(WX3RDPARTYLIBPOSTFIX).lib wxjpeg$(WX3RDPARTYLIBPOSTFIX).lib wxpng$(WX3RDPARTYLIBPOSTFIX).lib wxzlib$(WX3RDPARTYLIBPOSTFIX).lib wxregex$(WXLIBPOSTFIX).lib wxexpat$(WX3RDPARTYLIBPOSTFIX).lib kernel32.lib user32.lib gdi32.lib comdlg32.lib winspool.lib winmm.lib shell32.lib comctl32.lib ole32.lib oleaut32.lib uuid.lib rpcrt4.lib advapi32.lib wsock32.lib oleacc.lib
<<

wxsqlite3$(WXLIBPOSTFIX).lib: $(WXSQLITE3_OBJECTS)
	if exist $@ del $@
	link /LIB /NOLOGO /OUT:$@ @<<
	$(WXSQLITE3_OBJECTS)
<<

rec$(WXLIBPOSTFIX).lib: rec_dummy.obj  $(REC_OBJECTS)
	if exist $@ del $@
	link /LIB /NOLOGO /OUT:$@ @<<
	$(REC_OBJECTS)
<<

reccl$(WXLIBPOSTFIX).lib: $(RECCL_OBJECTS)
	if exist $@ del $@
	link /LIB /NOLOGO /OUT:$@ @<<
	$(RECCL_OBJECTS)
<<

recgui$(WXLIBPOSTFIX).lib: $(RECGUI_OBJECTS)
	if exist $@ del $@
	link /LIB /NOLOGO /OUT:$@ @<<
	$(RECGUI_OBJECTS)
<<

tfp_dlgEd.obj: .\..\..\src\dlg\dlgEd.cpp
	$(CXX) /c /nologo /TP /Fo$@ $(TFP_CXXFLAGS) .\..\..\src\dlg\dlgEd.cpp

tfp_dlgEdFamily.obj: .\..\..\src\dlg\dlgEdFamily.cpp
	$(CXX) /c /nologo /TP /Fo$@ $(TFP_CXXFLAGS) .\..\..\src\dlg\dlgEdFamily.cpp

tfp_dlgEdIndividual.obj: .\..\..\src\dlg\dlgEdIndividual.cpp
	$(CXX) /c /nologo /TP /Fo$@ $(TFP_CXXFLAGS) .\..\..\src\dlg\dlgEdIndividual.cpp

tfp_dlgEdPersona.obj: .\..\..\src\dlg\dlgEdPersona.cpp
	$(CXX) /c /nologo /TP /Fo$@ $(TFP_CXXFLAGS) .\..\..\src\dlg\dlgEdPersona.cpp

tfp_dlgEdRole.obj: .\..\..\src\dlg\dlgEdRole.cpp
	$(CXX) /c /nologo /TP /Fo$@ $(TFP_CXXFLAGS) .\..\..\src\dlg\dlgEdRole.cpp

tfp_dlgEdSystem.obj: .\..\..\src\dlg\dlgEdSystem.cpp
	$(CXX) /c /nologo /TP /Fo$@ $(TFP_CXXFLAGS) .\..\..\src\dlg\dlgEdSystem.cpp

tfp_dlgNote.obj: .\..\..\src\dlg\dlgNote.cpp
	$(CXX) /c /nologo /TP /Fo$@ $(TFP_CXXFLAGS) .\..\..\src\dlg\dlgNote.cpp

tfp_dlgRecTableCtrl.obj: .\..\..\src\dlg\dlgRecTableCtrl.cpp
	$(CXX) /c /nologo /TP /Fo$@ $(TFP_CXXFLAGS) .\..\..\src\dlg\dlgRecTableCtrl.cpp

tfp_dlgSelect.obj: .\..\..\src\dlg\dlgSelect.cpp
	$(CXX) /c /nologo /TP /Fo$@ $(TFP_CXXFLAGS) .\..\..\src\dlg\dlgSelect.cpp

tfp_dlgSelIndividual.obj: .\..\..\src\dlg\dlgSelIndividual.cpp
	$(CXX) /c /nologo /TP /Fo$@ $(TFP_CXXFLAGS) .\..\..\src\dlg\dlgSelIndividual.cpp

tfp_fbDlg.obj: .\..\..\src\dlg\fbDlg.cpp
	$(CXX) /c /nologo /TP /Fo$@ $(TFP_CXXFLAGS) .\..\..\src\dlg\fbDlg.cpp

tfp_tfpApp.obj: .\..\..\src\tfpApp.cpp
	$(CXX) /c /nologo /TP /Fo$@ $(TFP_CXXFLAGS) .\..\..\src\tfpApp.cpp

tfp_tfpFrame.obj: .\..\..\src\tfpFrame.cpp
	$(CXX) /c /nologo /TP /Fo$@ $(TFP_CXXFLAGS) .\..\..\src\tfpFrame.cpp

tfp_tfpMemory.obj: .\..\..\src\tfpMemory.cpp
	$(CXX) /c /nologo /TP /Fo$@ $(TFP_CXXFLAGS) .\..\..\src\tfpMemory.cpp

tfp_tfpRdGed.obj: .\..\..\src\tfpRdGed.cpp
	$(CXX) /c /nologo /TP /Fo$@ $(TFP_CXXFLAGS) .\..\..\src\tfpRdGed.cpp

tfp_tfpVersion.obj: .\..\..\src\tfpVersion.cpp
	$(CXX) /c /nologo /TP /Fo$@ $(TFP_CXXFLAGS) .\..\..\src\tfpVersion.cpp

tfp_tfpWr.obj: .\..\..\src\tfpWr.cpp
	$(CXX) /c /nologo /TP /Fo$@ $(TFP_CXXFLAGS) .\..\..\src\tfpWr.cpp

tfp_tfpWrAdmin.obj: .\..\..\src\tfpWrAdmin.cpp
	$(CXX) /c /nologo /TP /Fo$@ $(TFP_CXXFLAGS) .\..\..\src\tfpWrAdmin.cpp

tfp_tfpWrChart.obj: .\..\..\src\tfpWrChart.cpp
	$(CXX) /c /nologo /TP /Fo$@ $(TFP_CXXFLAGS) .\..\..\src\tfpWrChart.cpp

tfp_tfpWrEvent.obj: .\..\..\src\tfpWrEvent.cpp
	$(CXX) /c /nologo /TP /Fo$@ $(TFP_CXXFLAGS) .\..\..\src\tfpWrEvent.cpp

tfp_tfpWrFamily.obj: .\..\..\src\tfpWrFamily.cpp
	$(CXX) /c /nologo /TP /Fo$@ $(TFP_CXXFLAGS) .\..\..\src\tfpWrFamily.cpp

tfp_tfpWrIndividual.obj: .\..\..\src\tfpWrIndividual.cpp
	$(CXX) /c /nologo /TP /Fo$@ $(TFP_CXXFLAGS) .\..\..\src\tfpWrIndividual.cpp

tfp_tfpWrName.obj: .\..\..\src\tfpWrName.cpp
	$(CXX) /c /nologo /TP /Fo$@ $(TFP_CXXFLAGS) .\..\..\src\tfpWrName.cpp

tfp_tfpWrNotes.obj: .\..\..\src\tfpWrNotes.cpp
	$(CXX) /c /nologo /TP /Fo$@ $(TFP_CXXFLAGS) .\..\..\src\tfpWrNotes.cpp

tfp_tfpWrReference.obj: .\..\..\src\tfpWrReference.cpp
	$(CXX) /c /nologo /TP /Fo$@ $(TFP_CXXFLAGS) .\..\..\src\tfpWrReference.cpp

tfp_webviewfshandler.obj: .\..\..\src\webviewfshandler.cpp
	$(CXX) /c /nologo /TP /Fo$@ $(TFP_CXXFLAGS) .\..\..\src\webviewfshandler.cpp

tfp_tfp.res: .\..\..\src\tfp.rc
	rc /fo$@  /d WIN32  /d _UNICODE $(__WXDEBUG_DEFINE_p_1) /d __WXMSW__ /i $(WX_DIR)\lib\$(COMPILER_PREFIX)$(WXCPU)_lib\msw$(WXLIBPOSTFIX) /i $(WX_DIR)\include $(______tfp__DEBUGINFO_6_p_1) /d _WINDOWS /i ..\..\include /i ..\..\src .\..\..\src\tfp.rc

tfp_dummy.obj: .\..\..\src\dummy.cpp
	$(CXX) /c /nologo /TP /Fo$@ $(TFP_CXXFLAGS) /Ycwx/wxprec.h .\..\..\src\dummy.cpp

calendar_calAstro.obj: .\..\..\src\cal\calAstro.cpp
	$(CXX) /c /nologo /TP /Fo$@ $(CALENDAR_CXXFLAGS) .\..\..\src\cal\calAstro.cpp

calendar_calendar.obj: .\..\..\src\cal\calendar.cpp
	$(CXX) /c /nologo /TP /Fo$@ $(CALENDAR_CXXFLAGS) .\..\..\src\cal\calendar.cpp

calendar_calFrench.obj: .\..\..\src\cal\calFrench.cpp
	$(CXX) /c /nologo /TP /Fo$@ $(CALENDAR_CXXFLAGS) .\..\..\src\cal\calFrench.cpp

calendar_calGregorian.obj: .\..\..\src\cal\calGregorian.cpp
	$(CXX) /c /nologo /TP /Fo$@ $(CALENDAR_CXXFLAGS) .\..\..\src\cal\calGregorian.cpp

calendar_calJulian.obj: .\..\..\src\cal\calJulian.cpp
	$(CXX) /c /nologo /TP /Fo$@ $(CALENDAR_CXXFLAGS) .\..\..\src\cal\calJulian.cpp

calendar_calMath.obj: .\..\..\src\cal\calMath.cpp
	$(CXX) /c /nologo /TP /Fo$@ $(CALENDAR_CXXFLAGS) .\..\..\src\cal\calMath.cpp

calendar_calParse.obj: .\..\..\src\cal\calParse.cpp
	$(CXX) /c /nologo /TP /Fo$@ $(CALENDAR_CXXFLAGS) .\..\..\src\cal\calParse.cpp

calendar_calRecord.obj: .\..\..\src\cal\calRecord.cpp
	$(CXX) /c /nologo /TP /Fo$@ $(CALENDAR_CXXFLAGS) .\..\..\src\cal\calRecord.cpp

calendar_dummy.obj: .\..\..\src\dummy.cpp
	$(CXX) /c /nologo /TP /Fo$@ $(CALENDAR_CXXFLAGS) /Ycwx/wxprec.h .\..\..\src\dummy.cpp

tests_dummy.obj: .\..\..\tests\dummy.cpp
	$(CXX) /c /nologo /TP /Fo$@ $(TESTS_CXXFLAGS) /Yctestprec.h .\..\..\tests\dummy.cpp

tests_test.obj: .\..\..\tests\test.cpp
	$(CXX) /c /nologo /TP /Fo$@ $(TESTS_CXXFLAGS) .\..\..\tests\test.cpp

tests_testCalendar.obj: .\..\..\tests\cal\testCalendar.cpp
	$(CXX) /c /nologo /TP /Fo$@ $(TESTS_CXXFLAGS) .\..\..\tests\cal\testCalendar.cpp

tests_testDatabase.obj: .\..\..\tests\rec\testDatabase.cpp
	$(CXX) /c /nologo /TP /Fo$@ $(TESTS_CXXFLAGS) .\..\..\tests\rec\testDatabase.cpp

calcalc_calCalc.obj: .\..\..\utils\cal\calCalc.cpp
	$(CXX) /c /nologo /TP /Fo$@ $(CALCALC_CXXFLAGS) .\..\..\utils\cal\calCalc.cpp

file2cpp_fcMain.obj: .\..\..\utils\file2cpp\fcMain.cpp
	$(CXX) /c /nologo /TP /Fo$@ $(FILE2CPP_CXXFLAGS) .\..\..\utils\file2cpp\fcMain.cpp

doccore_dcMain.obj: .\..\..\utils\doccore\dcMain.cpp
	$(CXX) /c /nologo /TP /Fo$@ $(DOCCORE_CXXFLAGS) .\..\..\utils\doccore\dcMain.cpp

wxsqlite3_wxsqlite3.obj: .\..\..\3rdparty\wxsqlite3\wxsqlite3.cpp
	$(CXX) /c /nologo /TP /Fo$@ $(WXSQLITE3_CXXFLAGS) .\..\..\3rdparty\wxsqlite3\wxsqlite3.cpp

wxsqlite3_sqlite3.obj: .\..\..\3rdparty\wxsqlite3\sqlite3.c
	$(CC) /c /nologo /TC /Fo$@ $(WXSQLITE3_CFLAGS) .\..\..\3rdparty\wxsqlite3\sqlite3.c

rec_recContact.obj: .\..\..\src\rec\recContact.cpp
	$(CXX) /c /nologo /TP /Fo$@ $(REC_CXXFLAGS) .\..\..\src\rec\recContact.cpp

rec_recDatabase.obj: .\..\..\src\rec\recDatabase.cpp
	$(CXX) /c /nologo /TP /Fo$@ $(REC_CXXFLAGS) .\..\..\src\rec\recDatabase.cpp

rec_recDate.obj: .\..\..\src\rec\recDate.cpp
	$(CXX) /c /nologo /TP /Fo$@ $(REC_CXXFLAGS) .\..\..\src\rec\recDate.cpp

rec_recEvent.obj: .\..\..\src\rec\recEvent.cpp
	$(CXX) /c /nologo /TP /Fo$@ $(REC_CXXFLAGS) .\..\..\src\rec\recEvent.cpp

rec_recFilterEvent.obj: .\..\..\src\rec\recFilterEvent.cpp
	$(CXX) /c /nologo /TP /Fo$@ $(REC_CXXFLAGS) .\..\..\src\rec\recFilterEvent.cpp

rec_recGedParse.obj: .\..\..\src\rec\recGedParse.cpp
	$(CXX) /c /nologo /TP /Fo$@ $(REC_CXXFLAGS) .\..\..\src\rec\recGedParse.cpp

rec_recIndividual.obj: .\..\..\src\rec\recIndividual.cpp
	$(CXX) /c /nologo /TP /Fo$@ $(REC_CXXFLAGS) .\..\..\src\rec\recIndividual.cpp

rec_recLink.obj: .\..\..\src\rec\recLink.cpp
	$(CXX) /c /nologo /TP /Fo$@ $(REC_CXXFLAGS) .\..\..\src\rec\recLink.cpp

rec_recName.obj: .\..\..\src\rec\recName.cpp
	$(CXX) /c /nologo /TP /Fo$@ $(REC_CXXFLAGS) .\..\..\src\rec\recName.cpp

rec_recPersona.obj: .\..\..\src\rec\recPersona.cpp
	$(CXX) /c /nologo /TP /Fo$@ $(REC_CXXFLAGS) .\..\..\src\rec\recPersona.cpp

rec_recPlace.obj: .\..\..\src\rec\recPlace.cpp
	$(CXX) /c /nologo /TP /Fo$@ $(REC_CXXFLAGS) .\..\..\src\rec\recPlace.cpp

rec_recReference.obj: .\..\..\src\rec\recReference.cpp
	$(CXX) /c /nologo /TP /Fo$@ $(REC_CXXFLAGS) .\..\..\src\rec\recReference.cpp

rec_recRelationship.obj: .\..\..\src\rec\recRelationship.cpp
	$(CXX) /c /nologo /TP /Fo$@ $(REC_CXXFLAGS) .\..\..\src\rec\recRelationship.cpp

rec_recSource.obj: .\..\..\src\rec\recSource.cpp
	$(CXX) /c /nologo /TP /Fo$@ $(REC_CXXFLAGS) .\..\..\src\rec\recSource.cpp

rec_recSystem.obj: .\..\..\src\rec\recSystem.cpp
	$(CXX) /c /nologo /TP /Fo$@ $(REC_CXXFLAGS) .\..\..\src\rec\recSystem.cpp

rec_recUser.obj: .\..\..\src\rec\recUser.cpp
	$(CXX) /c /nologo /TP /Fo$@ $(REC_CXXFLAGS) .\..\..\src\rec\recUser.cpp

rec_recVersion.obj: .\..\..\src\rec\recVersion.cpp
	$(CXX) /c /nologo /TP /Fo$@ $(REC_CXXFLAGS) .\..\..\src\rec\recVersion.cpp

rec_dummy.obj: .\..\..\src\dummy.cpp
	$(CXX) /c /nologo /TP /Fo$@ $(REC_CXXFLAGS) /Ycwx/wxprec.h .\..\..\src\dummy.cpp

reccl_reccl.obj: .\..\..\src\rec\reccl.cpp
	$(CXX) /c /nologo /TP /Fo$@ $(RECCL_CXXFLAGS) .\..\..\src\rec\reccl.cpp

recgui_recgui.obj: .\..\..\src\rec\recgui.cpp
	$(CXX) /c /nologo /TP /Fo$@ $(RECGUI_CXXFLAGS) .\..\..\src\rec\recgui.cpp

recgui_fbRgDialog.obj: .\..\..\src\rg\fbRgDialog.cpp
	$(CXX) /c /nologo /TP /Fo$@ $(RECGUI_CXXFLAGS) .\..\..\src\rg\fbRgDialog.cpp

recgui_rgCompareEvent.obj: .\..\..\src\rg\rgCompareEvent.cpp
	$(CXX) /c /nologo /TP /Fo$@ $(RECGUI_CXXFLAGS) .\..\..\src\rg\rgCompareEvent.cpp

recgui_rgCrName.obj: .\..\..\src\rg\rgCrName.cpp
	$(CXX) /c /nologo /TP /Fo$@ $(RECGUI_CXXFLAGS) .\..\..\src\rg\rgCrName.cpp

recgui_rgDialogs.obj: .\..\..\src\rg\rgDialogs.cpp
	$(CXX) /c /nologo /TP /Fo$@ $(RECGUI_CXXFLAGS) .\..\..\src\rg\rgDialogs.cpp

recgui_rgEdContact.obj: .\..\..\src\rg\rgEdContact.cpp
	$(CXX) /c /nologo /TP /Fo$@ $(RECGUI_CXXFLAGS) .\..\..\src\rg\rgEdContact.cpp

recgui_rgEdDate.obj: .\..\..\src\rg\rgEdDate.cpp
	$(CXX) /c /nologo /TP /Fo$@ $(RECGUI_CXXFLAGS) .\..\..\src\rg\rgEdDate.cpp

recgui_rgEdEvent.obj: .\..\..\src\rg\rgEdEvent.cpp
	$(CXX) /c /nologo /TP /Fo$@ $(RECGUI_CXXFLAGS) .\..\..\src\rg\rgEdEvent.cpp

recgui_rgEdEventType.obj: .\..\..\src\rg\rgEdEventType.cpp
	$(CXX) /c /nologo /TP /Fo$@ $(RECGUI_CXXFLAGS) .\..\..\src\rg\rgEdEventType.cpp

recgui_rgEdEvidEvent.obj: .\..\..\src\rg\rgEdEvidEvent.cpp
	$(CXX) /c /nologo /TP /Fo$@ $(RECGUI_CXXFLAGS) .\..\..\src\rg\rgEdEvidEvent.cpp

recgui_rgEdName.obj: .\..\..\src\rg\rgEdName.cpp
	$(CXX) /c /nologo /TP /Fo$@ $(RECGUI_CXXFLAGS) .\..\..\src\rg\rgEdName.cpp

recgui_rgEdNamePart.obj: .\..\..\src\rg\rgEdNamePart.cpp
	$(CXX) /c /nologo /TP /Fo$@ $(RECGUI_CXXFLAGS) .\..\..\src\rg\rgEdNamePart.cpp

recgui_rgEdPerIndEvent.obj: .\..\..\src\rg\rgEdPerIndEvent.cpp
	$(CXX) /c /nologo /TP /Fo$@ $(RECGUI_CXXFLAGS) .\..\..\src\rg\rgEdPerIndEvent.cpp

recgui_rgEdPlace.obj: .\..\..\src\rg\rgEdPlace.cpp
	$(CXX) /c /nologo /TP /Fo$@ $(RECGUI_CXXFLAGS) .\..\..\src\rg\rgEdPlace.cpp

recgui_rgEdReference.obj: .\..\..\src\rg\rgEdReference.cpp
	$(CXX) /c /nologo /TP /Fo$@ $(RECGUI_CXXFLAGS) .\..\..\src\rg\rgEdReference.cpp

recgui_rgEdRelationship.obj: .\..\..\src\rg\rgEdRelationship.cpp
	$(CXX) /c /nologo /TP /Fo$@ $(RECGUI_CXXFLAGS) .\..\..\src\rg\rgEdRelationship.cpp

recgui_rgEdResearcher.obj: .\..\..\src\rg\rgEdResearcher.cpp
	$(CXX) /c /nologo /TP /Fo$@ $(RECGUI_CXXFLAGS) .\..\..\src\rg\rgEdResearcher.cpp

recgui_rgEdRole.obj: .\..\..\src\rg\rgEdRole.cpp
	$(CXX) /c /nologo /TP /Fo$@ $(RECGUI_CXXFLAGS) .\..\..\src\rg\rgEdRole.cpp

recgui_rgSelect.obj: .\..\..\src\rg\rgSelect.cpp
	$(CXX) /c /nologo /TP /Fo$@ $(RECGUI_CXXFLAGS) .\..\..\src\rg\rgSelect.cpp

recgui_rgSelIndEvent.obj: .\..\..\src\rg\rgSelIndEvent.cpp
	$(CXX) /c /nologo /TP /Fo$@ $(RECGUI_CXXFLAGS) .\..\..\src\rg\rgSelIndEvent.cpp

recgui_rgTableCtrl.obj: .\..\..\src\rg\rgTableCtrl.cpp
	$(CXX) /c /nologo /TP /Fo$@ $(RECGUI_CXXFLAGS) .\..\..\src\rg\rgTableCtrl.cpp

