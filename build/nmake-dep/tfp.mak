# =========================================================================
#     This makefile was generated by
#     Bakefile 0.2.11 (http://www.bakefile.org)
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
WX_VERSION = 31

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
TFP_CXXFLAGS = /MD$(VAR_19) /DWIN32 /D_UNICODE $(__WXDEBUG_DEFINE_p) /D__WXMSW__ \
	/I$(WX_DIR)\lib\$(COMPILER_PREFIX)$(WXCPU)_lib\msw$(WXLIBPOSTFIX) \
	/I$(WX_DIR)\include $(VAR) $(VAR_18) $(p) /Fdtfp.pdb /D_WINDOWS \
	/I..\..\include /I..\..\src /GR /EHsc /Yu"wx/wxprec.h" /Fp"wxprec_tfp.pch" \
	$(CPPFLAGS) $(CXXFLAGS)
TFP_OBJECTS =  \
	tfp_tfpApp.obj \
	tfp_tfpExportGed.obj \
	tfp_tfpFrame.obj \
	tfp_tfpMemory.obj \
	tfp_tfpNote.obj \
	tfp_tfpRdGed.obj \
	tfp_tfpVersion.obj \
	tfp_tfpWr.obj \
	tfp_tfpWrAdmin.obj \
	tfp_tfpWrChart.obj \
	tfp_tfpWrEvent.obj \
	tfp_tfpWrEventa.obj \
	tfp_tfpWrEventaIndex.obj \
	tfp_tfpWrEventIndex.obj \
	tfp_tfpWrFamily.obj \
	tfp_tfpWrGallery.obj \
	tfp_tfpWrIndividual.obj \
	tfp_tfpWrMedia.obj \
	tfp_tfpWrName.obj \
	tfp_tfpWrNotes.obj \
	tfp_tfpWrPersona.obj \
	tfp_tfpWrReference.obj \
	tfp_dummy.obj
TFP_RESOURCES =  \
	tfp_tfp.res
CALENDAR_CXXFLAGS = /MD$(VAR_19) /DWIN32 /D_UNICODE $(__WXDEBUG_DEFINE_p) \
	/D__WXMSW__ \
	/I$(WX_DIR)\lib\$(COMPILER_PREFIX)$(WXCPU)_lib\msw$(WXLIBPOSTFIX) \
	/I$(WX_DIR)\include $(VAR) $(VAR_18) $(p) /Fdcalendar$(WXLIBPOSTFIX).pdb \
	/I..\..\include\cal /I..\..\include /GR /EHsc /Yu"wx/wxprec.h" \
	/Fp"wxprec_calendar.pch" $(CPPFLAGS) $(CXXFLAGS)
CALENDAR_OBJECTS =  \
	calendar_calAstro.obj \
	calendar_calendar.obj \
	calendar_calFrench.obj \
	calendar_calGregorian.obj \
	calendar_calHebrew.obj \
	calendar_calIslamic.obj \
	calendar_calJulian.obj \
	calendar_calMath.obj \
	calendar_calParse.obj \
	calendar_calRecord.obj \
	calendar_dummy.obj
TESTS_CXXFLAGS = /MD$(VAR_19) /DWIN32 /D_UNICODE $(__WXDEBUG_DEFINE_p) \
	/D__WXMSW__ \
	/I$(WX_DIR)\lib\$(COMPILER_PREFIX)$(WXCPU)_lib\msw$(WXLIBPOSTFIX) \
	/I$(WX_DIR)\include $(VAR) $(VAR_18) $(p) /Fdtests.pdb /D_CONSOLE \
	/I..\..\include /I..\..\tests /I$(CPPUNIT)\include /GR /EHsc /Yu"testprec.h" \
	/Fp"wxprec_tests.pch" $(CPPFLAGS) $(CXXFLAGS)
TESTS_OBJECTS =  \
	tests_dummy.obj \
	tests_test.obj \
	tests_testCalendar.obj \
	tests_testDatabase.obj
CALCALC_CXXFLAGS = /MD$(VAR_19) /DWIN32 /D_UNICODE $(__WXDEBUG_DEFINE_p) \
	/D__WXMSW__ \
	/I$(WX_DIR)\lib\$(COMPILER_PREFIX)$(WXCPU)_lib\msw$(WXLIBPOSTFIX) \
	/I$(WX_DIR)\include $(VAR) $(VAR_18) $(p) /Fdcalcalc.pdb /D_CONSOLE \
	/I..\..\include /GR /EHsc $(CPPFLAGS) $(CXXFLAGS)
CALCALC_OBJECTS =  \
	calcalc_calCalc.obj
DOCCORE_CXXFLAGS = /MD$(VAR_19) /DWIN32 /D_UNICODE $(__WXDEBUG_DEFINE_p) \
	/D__WXMSW__ \
	/I$(WX_DIR)\lib\$(COMPILER_PREFIX)$(WXCPU)_lib\msw$(WXLIBPOSTFIX) \
	/I$(WX_DIR)\include $(VAR) $(VAR_18) $(p) /Fddoccore.pdb /D_CONSOLE \
	/I..\..\include /GR /EHsc $(CPPFLAGS) $(CXXFLAGS)
DOCCORE_OBJECTS =  \
	doccore_dcMain.obj
WXSQLITE3_CFLAGS = /MD$(VAR_19) /DWIN32 /D_UNICODE $(__WXDEBUG_DEFINE_p) \
	/D__WXMSW__ \
	/I$(WX_DIR)\lib\$(COMPILER_PREFIX)$(WXCPU)_lib\msw$(WXLIBPOSTFIX) \
	/I$(WX_DIR)\include $(VAR) $(VAR_18) $(p) /Fdwxsqlite3$(WXLIBPOSTFIX).pdb \
	/DSQLITE_ENABLE_RTREE /I..\..\include $(CPPFLAGS) $(CFLAGS)
WXSQLITE3_CXXFLAGS = /MD$(VAR_19) /DWIN32 /D_UNICODE $(__WXDEBUG_DEFINE_p) \
	/D__WXMSW__ \
	/I$(WX_DIR)\lib\$(COMPILER_PREFIX)$(WXCPU)_lib\msw$(WXLIBPOSTFIX) \
	/I$(WX_DIR)\include $(VAR) $(VAR_18) $(p) /Fdwxsqlite3$(WXLIBPOSTFIX).pdb \
	/DSQLITE_ENABLE_RTREE /I..\..\include /GR /EHsc $(CPPFLAGS) $(CXXFLAGS)
WXSQLITE3_OBJECTS =  \
	wxsqlite3_wxsqlite3.obj \
	wxsqlite3_sqlite3.obj
REC_CXXFLAGS = /MD$(VAR_19) /DWIN32 /D_UNICODE $(__WXDEBUG_DEFINE_p) /D__WXMSW__ \
	/I$(WX_DIR)\lib\$(COMPILER_PREFIX)$(WXCPU)_lib\msw$(WXLIBPOSTFIX) \
	/I$(WX_DIR)\include $(VAR) $(VAR_18) $(p) /Fdrec$(WXLIBPOSTFIX).pdb \
	/I..\..\include\rec /I..\..\include /GR /EHsc /Yu"wx/wxprec.h" \
	/Fp"wxprec_rec.pch" $(CPPFLAGS) $(CXXFLAGS)
REC_OBJECTS =  \
	rec_recAssociate.obj \
	rec_recContact.obj \
	rec_recDatabase.obj \
	rec_recDate.obj \
	rec_recEvent.obj \
	rec_recEventa.obj \
	rec_recEventaPersona.obj \
	rec_recEventEventa.obj \
	rec_recEventType.obj \
	rec_recEventTypeRole.obj \
	rec_recFamEvent.obj \
	rec_recFamEventa.obj \
	rec_recFamIndEventa.obj \
	rec_recFilterEvent.obj \
	rec_recGallery.obj \
	rec_recGalleryMedia.obj \
	rec_recGedExport.obj \
	rec_recGedParse.obj \
	rec_recHelper.obj \
	rec_recIndEvent.obj \
	rec_recIndividual.obj \
	rec_recIndPersona.obj \
	rec_recMedia.obj \
	rec_recMediaData.obj \
	rec_recName.obj \
	rec_recPersona.obj \
	rec_recPlace.obj \
	rec_recReference.obj \
	rec_recSource.obj \
	rec_recSystem.obj \
	rec_recUser.obj \
	rec_recUpgrade.obj \
	rec_recVersion.obj \
	rec_dummy.obj
RECCL_CXXFLAGS = /MD$(VAR_19) /DWIN32 /D_UNICODE $(__WXDEBUG_DEFINE_p) \
	/D__WXMSW__ \
	/I$(WX_DIR)\lib\$(COMPILER_PREFIX)$(WXCPU)_lib\msw$(WXLIBPOSTFIX) \
	/I$(WX_DIR)\include $(VAR) $(VAR_18) $(p) /Fdreccl$(WXLIBPOSTFIX).pdb \
	/I..\..\include\rec /I..\..\include /GR /EHsc $(CPPFLAGS) $(CXXFLAGS)
RECCL_OBJECTS =  \
	reccl_reccl.obj
RECGUI_CXXFLAGS = /MD$(VAR_19) /DWIN32 /D_UNICODE $(__WXDEBUG_DEFINE_p) \
	/D__WXMSW__ \
	/I$(WX_DIR)\lib\$(COMPILER_PREFIX)$(WXCPU)_lib\msw$(WXLIBPOSTFIX) \
	/I$(WX_DIR)\include $(VAR) $(VAR_18) $(p) /Fdrecgui$(WXLIBPOSTFIX).pdb \
	/I..\..\include\rec /I..\..\include\rg /I..\..\include /GR /EHsc $(CPPFLAGS) \
	$(CXXFLAGS)
RECGUI_OBJECTS =  \
	recgui_fbRgCreateDatabase.obj \
	recgui_fbRgEditGallery.obj \
	recgui_fbRgEditMedia.obj \
	recgui_fbRgEditReference.obj \
	recgui_fbRgSelect.obj \
	recgui_fbRgViewMedia.obj \
	recgui_fbRgDialog.obj \
	recgui_recgui.obj \
	recgui_rgCompareEvent.obj \
	recgui_rgCrDatabase.obj \
	recgui_rgCrIndividual.obj \
	recgui_rgCrName.obj \
	recgui_rgEdContact.obj \
	recgui_rgEdDate.obj \
	recgui_rgEdEvent.obj \
	recgui_rgEdEventa.obj \
	recgui_rgEdEventEventa.obj \
	recgui_rgEdEventType.obj \
	recgui_rgEdFamily.obj \
	recgui_rgEdGallery.obj \
	recgui_rgEdIndividual.obj \
	recgui_rgEdMedia.obj \
	recgui_rgEdName.obj \
	recgui_rgEdNamePart.obj \
	recgui_rgEdPerIndEvent.obj \
	recgui_rgEdPersona.obj \
	recgui_rgEdPlace.obj \
	recgui_rgEdReference.obj \
	recgui_rgEdRelDate.obj \
	recgui_rgEdResearcher.obj \
	recgui_rgEdRole.obj \
	recgui_rgEdSystem.obj \
	recgui_rgEdUser.obj \
	recgui_rgImagePanel.obj \
	recgui_rgIndividual.obj \
	recgui_rgSelect.obj \
	recgui_rgSelEvent.obj \
	recgui_rgTableCtrl.obj \
	recgui_rgViewMedia.obj

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
____tfp__DEBUGINFO_9 = $(VAR_11)
!endif
!if "$(WX_DEBUG)" == "0"
____tests__DEBUGINFO_34 = 
!endif
!if "$(WX_DEBUG)" == "1"
____tests__DEBUGINFO_34 = $(VAR_11)
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
____calcalc__DEBUGINFO_49 = $(VAR_11)
!endif
!if "$(WX_DEBUG)" == "0"
____doccore__DEBUGINFO_62 = 
!endif
!if "$(WX_DEBUG)" == "1"
____doccore__DEBUGINFO_62 = $(VAR_11)
!endif
!if "$(WX_DEBUG)" == "0"
VAR_9 = 
!endif
!if "$(WX_DEBUG)" == "1"
VAR_9 = /DEBUG
!endif
!if "$(WX_DEBUG)" == "0"
VAR_11 = /opt:ref /opt:icf
!endif
!if "$(WX_DEBUG)" == "1"
VAR_11 = 
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
VAR_18 = 
!endif
!if "$(WX_DEBUG)" == "1"
VAR_18 = /Zi
!endif
!if "$(WX_DEBUG)" == "0"
p = 
!endif
!if "$(WX_DEBUG)" == "1"
p = /D_DEBUG
!endif
!if "$(WX_DEBUG)" == "0"
VAR_19 = 
!endif
!if "$(WX_DEBUG)" == "1"
VAR_19 = d
!endif


### Targets: ###

all: test_for_selected_wxbuild tfp.exe calendar$(WXLIBPOSTFIX).lib tests.exe calcalc.exe doccore.exe wxsqlite3$(WXLIBPOSTFIX).lib rec$(WXLIBPOSTFIX).lib reccl$(WXLIBPOSTFIX).lib recgui$(WXLIBPOSTFIX).lib

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

../../src/generated/tfpText.ci: ..\..\src\embed\tfpText.f2c ..\..\src\embed\startup.htm ..\..\src\embed\tab.css ..\..\src\embed\tfp.css
	file2cpp -v -o ../../src/tfpText.h ../../src/embed/tfpText.f2c

../../src/tfpMemory.cpp: ..\..\src\tfpText.h

tfp.exe: tfp_dummy.obj  $(TFP_OBJECTS) tfp_tfp.res recgui$(WXLIBPOSTFIX).lib rec$(WXLIBPOSTFIX).lib calendar$(WXLIBPOSTFIX).lib wxsqlite3$(WXLIBPOSTFIX).lib
	link /NOLOGO /OUT:$@  /LIBPATH:$(WX_DIR)\lib\$(COMPILER_PREFIX)$(WXCPU)_lib $(WXMACHINE_FLAG) $(VAR_9) /pdb:"tfp.pdb" $(____tfp__DEBUGINFO_9) /SUBSYSTEM:WINDOWS $(LDFLAGS) @<<
	$(TFP_OBJECTS) $(TFP_RESOURCES)  recgui$(WXLIBPOSTFIX).lib rec$(WXLIBPOSTFIX).lib calendar$(WXLIBPOSTFIX).lib wxsqlite3$(WXLIBPOSTFIX).lib wxmsw$(WX_VERSION)$(WXLIBPOSTFIX)_webview.lib wxmsw$(WX_VERSION)$(WXLIBPOSTFIX)_adv.lib wxmsw$(WX_VERSION)$(WXLIBPOSTFIX)_core.lib wxbase$(WX_VERSION)$(WXLIBPOSTFIX).lib wxtiff$(WX3RDPARTYLIBPOSTFIX).lib wxjpeg$(WX3RDPARTYLIBPOSTFIX).lib wxpng$(WX3RDPARTYLIBPOSTFIX).lib wxzlib$(WX3RDPARTYLIBPOSTFIX).lib wxregex$(WXLIBPOSTFIX).lib wxexpat$(WX3RDPARTYLIBPOSTFIX).lib kernel32.lib user32.lib gdi32.lib comdlg32.lib winspool.lib winmm.lib shell32.lib comctl32.lib ole32.lib oleaut32.lib uuid.lib rpcrt4.lib advapi32.lib wsock32.lib oleacc.lib
<<

calendar$(WXLIBPOSTFIX).lib: calendar_dummy.obj  $(CALENDAR_OBJECTS)
	if exist $@ del $@
	link /LIB /NOLOGO /OUT:$@ @<<
	$(CALENDAR_OBJECTS)
<<

tests.exe: tests_dummy.obj  $(TESTS_OBJECTS) calendar$(WXLIBPOSTFIX).lib wxsqlite3$(WXLIBPOSTFIX).lib reccl$(WXLIBPOSTFIX).lib rec$(WXLIBPOSTFIX).lib
	link /NOLOGO /OUT:$@  /LIBPATH:$(WX_DIR)\lib\$(COMPILER_PREFIX)$(WXCPU)_lib $(WXMACHINE_FLAG) $(VAR_9) /pdb:"tests.pdb" $(____tests__DEBUGINFO_34) /SUBSYSTEM:CONSOLE /LIBPATH:$(CPPUNIT)\lib $(LDFLAGS) @<<
	$(TESTS_OBJECTS)   calendar$(WXLIBPOSTFIX).lib wxsqlite3$(WXLIBPOSTFIX).lib reccl$(WXLIBPOSTFIX).lib rec$(WXLIBPOSTFIX).lib $(____WX_DEBUG_39_p) wxmsw$(WX_VERSION)$(WXLIBPOSTFIX)_core.lib wxbase$(WX_VERSION)$(WXLIBPOSTFIX).lib wxbase$(WX_VERSION)$(WXLIBPOSTFIX)_net.lib wxtiff$(WX3RDPARTYLIBPOSTFIX).lib wxjpeg$(WX3RDPARTYLIBPOSTFIX).lib wxpng$(WX3RDPARTYLIBPOSTFIX).lib wxzlib$(WX3RDPARTYLIBPOSTFIX).lib wxregex$(WXLIBPOSTFIX).lib wxexpat$(WX3RDPARTYLIBPOSTFIX).lib kernel32.lib user32.lib gdi32.lib comdlg32.lib winspool.lib winmm.lib shell32.lib comctl32.lib ole32.lib oleaut32.lib uuid.lib rpcrt4.lib advapi32.lib wsock32.lib oleacc.lib
<<

calcalc.exe: $(CALCALC_OBJECTS) calendar$(WXLIBPOSTFIX).lib
	link /NOLOGO /OUT:$@  /LIBPATH:$(WX_DIR)\lib\$(COMPILER_PREFIX)$(WXCPU)_lib $(WXMACHINE_FLAG) $(VAR_9) /pdb:"calcalc.pdb" $(____calcalc__DEBUGINFO_49) /SUBSYSTEM:CONSOLE $(LDFLAGS) @<<
	$(CALCALC_OBJECTS)   calendar$(WXLIBPOSTFIX).lib wxbase$(WX_VERSION)$(WXLIBPOSTFIX).lib wxtiff$(WX3RDPARTYLIBPOSTFIX).lib wxjpeg$(WX3RDPARTYLIBPOSTFIX).lib wxpng$(WX3RDPARTYLIBPOSTFIX).lib wxzlib$(WX3RDPARTYLIBPOSTFIX).lib wxregex$(WXLIBPOSTFIX).lib wxexpat$(WX3RDPARTYLIBPOSTFIX).lib kernel32.lib user32.lib gdi32.lib comdlg32.lib winspool.lib winmm.lib shell32.lib comctl32.lib ole32.lib oleaut32.lib uuid.lib rpcrt4.lib advapi32.lib wsock32.lib oleacc.lib
<<

doccore.exe: $(DOCCORE_OBJECTS) calendar$(WXLIBPOSTFIX).lib wxsqlite3$(WXLIBPOSTFIX).lib rec$(WXLIBPOSTFIX).lib reccl$(WXLIBPOSTFIX).lib
	link /NOLOGO /OUT:$@  /LIBPATH:$(WX_DIR)\lib\$(COMPILER_PREFIX)$(WXCPU)_lib $(WXMACHINE_FLAG) $(VAR_9) /pdb:"doccore.pdb" $(____doccore__DEBUGINFO_62) /SUBSYSTEM:CONSOLE $(LDFLAGS) @<<
	$(DOCCORE_OBJECTS)   calendar$(WXLIBPOSTFIX).lib wxsqlite3$(WXLIBPOSTFIX).lib rec$(WXLIBPOSTFIX).lib reccl$(WXLIBPOSTFIX).lib wxbase$(WX_VERSION)$(WXLIBPOSTFIX).lib wxtiff$(WX3RDPARTYLIBPOSTFIX).lib wxjpeg$(WX3RDPARTYLIBPOSTFIX).lib wxpng$(WX3RDPARTYLIBPOSTFIX).lib wxzlib$(WX3RDPARTYLIBPOSTFIX).lib wxregex$(WXLIBPOSTFIX).lib wxexpat$(WX3RDPARTYLIBPOSTFIX).lib kernel32.lib user32.lib gdi32.lib comdlg32.lib winspool.lib winmm.lib shell32.lib comctl32.lib ole32.lib oleaut32.lib uuid.lib rpcrt4.lib advapi32.lib wsock32.lib oleacc.lib
<<

wxsqlite3$(WXLIBPOSTFIX).lib: $(WXSQLITE3_OBJECTS)
	if exist $@ del $@
	link /LIB /NOLOGO /OUT:$@ @<<
	$(WXSQLITE3_OBJECTS)
<<

../../src/rec/recDatabaseCreate.h: ..\..\src\rec\embed\recDatabaseCreate.f2c ..\..\src\rec\embed\recCreate.sql
	file2cpp -v -o ../../src/rec/recDatabaseCreate.h ../../src/rec/embed/recDatabaseCreate.f2c

../../src/rec/recDatabase.cpp: ..\..\src\rec\recDatabaseCreate.h

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

tfp_tfpApp.obj: .\..\..\src\tfp\tfpApp.cpp
	$(CXX) /c /nologo /TP /Fo$@ $(TFP_CXXFLAGS) .\..\..\src\tfp\tfpApp.cpp

tfp_tfpExportGed.obj: .\..\..\src\tfp\tfpExportGed.cpp
	$(CXX) /c /nologo /TP /Fo$@ $(TFP_CXXFLAGS) .\..\..\src\tfp\tfpExportGed.cpp

tfp_tfpFrame.obj: .\..\..\src\tfp\tfpFrame.cpp
	$(CXX) /c /nologo /TP /Fo$@ $(TFP_CXXFLAGS) .\..\..\src\tfp\tfpFrame.cpp

tfp_tfpMemory.obj: .\..\..\src\tfp\tfpMemory.cpp
	$(CXX) /c /nologo /TP /Fo$@ $(TFP_CXXFLAGS) .\..\..\src\tfp\tfpMemory.cpp

tfp_tfpNote.obj: .\..\..\src\tfp\tfpNote.cpp
	$(CXX) /c /nologo /TP /Fo$@ $(TFP_CXXFLAGS) .\..\..\src\tfp\tfpNote.cpp

tfp_tfpRdGed.obj: .\..\..\src\tfp\tfpRdGed.cpp
	$(CXX) /c /nologo /TP /Fo$@ $(TFP_CXXFLAGS) .\..\..\src\tfp\tfpRdGed.cpp

tfp_tfpVersion.obj: .\..\..\src\tfp\tfpVersion.cpp
	$(CXX) /c /nologo /TP /Fo$@ $(TFP_CXXFLAGS) .\..\..\src\tfp\tfpVersion.cpp

tfp_tfpWr.obj: .\..\..\src\tfp\tfpWr.cpp
	$(CXX) /c /nologo /TP /Fo$@ $(TFP_CXXFLAGS) .\..\..\src\tfp\tfpWr.cpp

tfp_tfpWrAdmin.obj: .\..\..\src\tfp\tfpWrAdmin.cpp
	$(CXX) /c /nologo /TP /Fo$@ $(TFP_CXXFLAGS) .\..\..\src\tfp\tfpWrAdmin.cpp

tfp_tfpWrChart.obj: .\..\..\src\tfp\tfpWrChart.cpp
	$(CXX) /c /nologo /TP /Fo$@ $(TFP_CXXFLAGS) .\..\..\src\tfp\tfpWrChart.cpp

tfp_tfpWrEvent.obj: .\..\..\src\tfp\tfpWrEvent.cpp
	$(CXX) /c /nologo /TP /Fo$@ $(TFP_CXXFLAGS) .\..\..\src\tfp\tfpWrEvent.cpp

tfp_tfpWrEventa.obj: .\..\..\src\tfp\tfpWrEventa.cpp
	$(CXX) /c /nologo /TP /Fo$@ $(TFP_CXXFLAGS) .\..\..\src\tfp\tfpWrEventa.cpp

tfp_tfpWrEventaIndex.obj: .\..\..\src\tfp\tfpWrEventaIndex.cpp
	$(CXX) /c /nologo /TP /Fo$@ $(TFP_CXXFLAGS) .\..\..\src\tfp\tfpWrEventaIndex.cpp

tfp_tfpWrEventIndex.obj: .\..\..\src\tfp\tfpWrEventIndex.cpp
	$(CXX) /c /nologo /TP /Fo$@ $(TFP_CXXFLAGS) .\..\..\src\tfp\tfpWrEventIndex.cpp

tfp_tfpWrFamily.obj: .\..\..\src\tfp\tfpWrFamily.cpp
	$(CXX) /c /nologo /TP /Fo$@ $(TFP_CXXFLAGS) .\..\..\src\tfp\tfpWrFamily.cpp

tfp_tfpWrGallery.obj: .\..\..\src\tfp\tfpWrGallery.cpp
	$(CXX) /c /nologo /TP /Fo$@ $(TFP_CXXFLAGS) .\..\..\src\tfp\tfpWrGallery.cpp

tfp_tfpWrIndividual.obj: .\..\..\src\tfp\tfpWrIndividual.cpp
	$(CXX) /c /nologo /TP /Fo$@ $(TFP_CXXFLAGS) .\..\..\src\tfp\tfpWrIndividual.cpp

tfp_tfpWrMedia.obj: .\..\..\src\tfp\tfpWrMedia.cpp
	$(CXX) /c /nologo /TP /Fo$@ $(TFP_CXXFLAGS) .\..\..\src\tfp\tfpWrMedia.cpp

tfp_tfpWrName.obj: .\..\..\src\tfp\tfpWrName.cpp
	$(CXX) /c /nologo /TP /Fo$@ $(TFP_CXXFLAGS) .\..\..\src\tfp\tfpWrName.cpp

tfp_tfpWrNotes.obj: .\..\..\src\tfp\tfpWrNotes.cpp
	$(CXX) /c /nologo /TP /Fo$@ $(TFP_CXXFLAGS) .\..\..\src\tfp\tfpWrNotes.cpp

tfp_tfpWrPersona.obj: .\..\..\src\tfp\tfpWrPersona.cpp
	$(CXX) /c /nologo /TP /Fo$@ $(TFP_CXXFLAGS) .\..\..\src\tfp\tfpWrPersona.cpp

tfp_tfpWrReference.obj: .\..\..\src\tfp\tfpWrReference.cpp
	$(CXX) /c /nologo /TP /Fo$@ $(TFP_CXXFLAGS) .\..\..\src\tfp\tfpWrReference.cpp

tfp_tfp.res: .\..\..\src\tfp\tfp.rc
	rc /fo$@  /d WIN32  /d _UNICODE $(__WXDEBUG_DEFINE_p_1) /d __WXMSW__ /i $(WX_DIR)\lib\$(COMPILER_PREFIX)$(WXCPU)_lib\msw$(WXLIBPOSTFIX) /i $(WX_DIR)\include $(______tfp__DEBUGINFO_6_p_1) /d _WINDOWS /i ..\..\include /i ..\..\src .\..\..\src\tfp\tfp.rc

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

calendar_calHebrew.obj: .\..\..\src\cal\calHebrew.cpp
	$(CXX) /c /nologo /TP /Fo$@ $(CALENDAR_CXXFLAGS) .\..\..\src\cal\calHebrew.cpp

calendar_calIslamic.obj: .\..\..\src\cal\calIslamic.cpp
	$(CXX) /c /nologo /TP /Fo$@ $(CALENDAR_CXXFLAGS) .\..\..\src\cal\calIslamic.cpp

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

doccore_dcMain.obj: .\..\..\utils\doccore\dcMain.cpp
	$(CXX) /c /nologo /TP /Fo$@ $(DOCCORE_CXXFLAGS) .\..\..\utils\doccore\dcMain.cpp

wxsqlite3_wxsqlite3.obj: .\..\..\3rdparty\wxsqlite3\wxsqlite3.cpp
	$(CXX) /c /nologo /TP /Fo$@ $(WXSQLITE3_CXXFLAGS) .\..\..\3rdparty\wxsqlite3\wxsqlite3.cpp

wxsqlite3_sqlite3.obj: .\..\..\3rdparty\wxsqlite3\sqlite3.c
	$(CC) /c /nologo /TC /Fo$@ $(WXSQLITE3_CFLAGS) .\..\..\3rdparty\wxsqlite3\sqlite3.c

rec_recAssociate.obj: .\..\..\src\rec\recAssociate.cpp
	$(CXX) /c /nologo /TP /Fo$@ $(REC_CXXFLAGS) .\..\..\src\rec\recAssociate.cpp

rec_recContact.obj: .\..\..\src\rec\recContact.cpp
	$(CXX) /c /nologo /TP /Fo$@ $(REC_CXXFLAGS) .\..\..\src\rec\recContact.cpp

rec_recDatabase.obj: .\..\..\src\rec\recDatabase.cpp
	$(CXX) /c /nologo /TP /Fo$@ $(REC_CXXFLAGS) .\..\..\src\rec\recDatabase.cpp

rec_recDate.obj: .\..\..\src\rec\recDate.cpp
	$(CXX) /c /nologo /TP /Fo$@ $(REC_CXXFLAGS) .\..\..\src\rec\recDate.cpp

rec_recEvent.obj: .\..\..\src\rec\recEvent.cpp
	$(CXX) /c /nologo /TP /Fo$@ $(REC_CXXFLAGS) .\..\..\src\rec\recEvent.cpp

rec_recEventa.obj: .\..\..\src\rec\recEventa.cpp
	$(CXX) /c /nologo /TP /Fo$@ $(REC_CXXFLAGS) .\..\..\src\rec\recEventa.cpp

rec_recEventaPersona.obj: .\..\..\src\rec\recEventaPersona.cpp
	$(CXX) /c /nologo /TP /Fo$@ $(REC_CXXFLAGS) .\..\..\src\rec\recEventaPersona.cpp

rec_recEventEventa.obj: .\..\..\src\rec\recEventEventa.cpp
	$(CXX) /c /nologo /TP /Fo$@ $(REC_CXXFLAGS) .\..\..\src\rec\recEventEventa.cpp

rec_recEventType.obj: .\..\..\src\rec\recEventType.cpp
	$(CXX) /c /nologo /TP /Fo$@ $(REC_CXXFLAGS) .\..\..\src\rec\recEventType.cpp

rec_recEventTypeRole.obj: .\..\..\src\rec\recEventTypeRole.cpp
	$(CXX) /c /nologo /TP /Fo$@ $(REC_CXXFLAGS) .\..\..\src\rec\recEventTypeRole.cpp

rec_recFamEvent.obj: .\..\..\src\rec\recFamEvent.cpp
	$(CXX) /c /nologo /TP /Fo$@ $(REC_CXXFLAGS) .\..\..\src\rec\recFamEvent.cpp

rec_recFamEventa.obj: .\..\..\src\rec\recFamEventa.cpp
	$(CXX) /c /nologo /TP /Fo$@ $(REC_CXXFLAGS) .\..\..\src\rec\recFamEventa.cpp

rec_recFamIndEventa.obj: .\..\..\src\rec\recFamIndEventa.cpp
	$(CXX) /c /nologo /TP /Fo$@ $(REC_CXXFLAGS) .\..\..\src\rec\recFamIndEventa.cpp

rec_recFilterEvent.obj: .\..\..\src\rec\recFilterEvent.cpp
	$(CXX) /c /nologo /TP /Fo$@ $(REC_CXXFLAGS) .\..\..\src\rec\recFilterEvent.cpp

rec_recGallery.obj: .\..\..\src\rec\recGallery.cpp
	$(CXX) /c /nologo /TP /Fo$@ $(REC_CXXFLAGS) .\..\..\src\rec\recGallery.cpp

rec_recGalleryMedia.obj: .\..\..\src\rec\recGalleryMedia.cpp
	$(CXX) /c /nologo /TP /Fo$@ $(REC_CXXFLAGS) .\..\..\src\rec\recGalleryMedia.cpp

rec_recGedExport.obj: .\..\..\src\rec\recGedExport.cpp
	$(CXX) /c /nologo /TP /Fo$@ $(REC_CXXFLAGS) .\..\..\src\rec\recGedExport.cpp

rec_recGedParse.obj: .\..\..\src\rec\recGedParse.cpp
	$(CXX) /c /nologo /TP /Fo$@ $(REC_CXXFLAGS) .\..\..\src\rec\recGedParse.cpp

rec_recHelper.obj: .\..\..\src\rec\recHelper.cpp
	$(CXX) /c /nologo /TP /Fo$@ $(REC_CXXFLAGS) .\..\..\src\rec\recHelper.cpp

rec_recIndEvent.obj: .\..\..\src\rec\recIndEvent.cpp
	$(CXX) /c /nologo /TP /Fo$@ $(REC_CXXFLAGS) .\..\..\src\rec\recIndEvent.cpp

rec_recIndividual.obj: .\..\..\src\rec\recIndividual.cpp
	$(CXX) /c /nologo /TP /Fo$@ $(REC_CXXFLAGS) .\..\..\src\rec\recIndividual.cpp

rec_recIndPersona.obj: .\..\..\src\rec\recIndPersona.cpp
	$(CXX) /c /nologo /TP /Fo$@ $(REC_CXXFLAGS) .\..\..\src\rec\recIndPersona.cpp

rec_recMedia.obj: .\..\..\src\rec\recMedia.cpp
	$(CXX) /c /nologo /TP /Fo$@ $(REC_CXXFLAGS) .\..\..\src\rec\recMedia.cpp

rec_recMediaData.obj: .\..\..\src\rec\recMediaData.cpp
	$(CXX) /c /nologo /TP /Fo$@ $(REC_CXXFLAGS) .\..\..\src\rec\recMediaData.cpp

rec_recName.obj: .\..\..\src\rec\recName.cpp
	$(CXX) /c /nologo /TP /Fo$@ $(REC_CXXFLAGS) .\..\..\src\rec\recName.cpp

rec_recPersona.obj: .\..\..\src\rec\recPersona.cpp
	$(CXX) /c /nologo /TP /Fo$@ $(REC_CXXFLAGS) .\..\..\src\rec\recPersona.cpp

rec_recPlace.obj: .\..\..\src\rec\recPlace.cpp
	$(CXX) /c /nologo /TP /Fo$@ $(REC_CXXFLAGS) .\..\..\src\rec\recPlace.cpp

rec_recReference.obj: .\..\..\src\rec\recReference.cpp
	$(CXX) /c /nologo /TP /Fo$@ $(REC_CXXFLAGS) .\..\..\src\rec\recReference.cpp

rec_recSource.obj: .\..\..\src\rec\recSource.cpp
	$(CXX) /c /nologo /TP /Fo$@ $(REC_CXXFLAGS) .\..\..\src\rec\recSource.cpp

rec_recSystem.obj: .\..\..\src\rec\recSystem.cpp
	$(CXX) /c /nologo /TP /Fo$@ $(REC_CXXFLAGS) .\..\..\src\rec\recSystem.cpp

rec_recUser.obj: .\..\..\src\rec\recUser.cpp
	$(CXX) /c /nologo /TP /Fo$@ $(REC_CXXFLAGS) .\..\..\src\rec\recUser.cpp

rec_recUpgrade.obj: .\..\..\src\rec\recUpgrade.cpp
	$(CXX) /c /nologo /TP /Fo$@ $(REC_CXXFLAGS) .\..\..\src\rec\recUpgrade.cpp

rec_recVersion.obj: .\..\..\src\rec\recVersion.cpp
	$(CXX) /c /nologo /TP /Fo$@ $(REC_CXXFLAGS) .\..\..\src\rec\recVersion.cpp

rec_dummy.obj: .\..\..\src\dummy.cpp
	$(CXX) /c /nologo /TP /Fo$@ $(REC_CXXFLAGS) /Ycwx/wxprec.h .\..\..\src\dummy.cpp

reccl_reccl.obj: .\..\..\src\rc\reccl.cpp
	$(CXX) /c /nologo /TP /Fo$@ $(RECCL_CXXFLAGS) .\..\..\src\rc\reccl.cpp

recgui_fbRgCreateDatabase.obj: .\..\..\src\rg\fb\fbRgCreateDatabase.cpp
	$(CXX) /c /nologo /TP /Fo$@ $(RECGUI_CXXFLAGS) .\..\..\src\rg\fb\fbRgCreateDatabase.cpp

recgui_fbRgEditGallery.obj: .\..\..\src\rg\fb\fbRgEditGallery.cpp
	$(CXX) /c /nologo /TP /Fo$@ $(RECGUI_CXXFLAGS) .\..\..\src\rg\fb\fbRgEditGallery.cpp

recgui_fbRgEditMedia.obj: .\..\..\src\rg\fb\fbRgEditMedia.cpp
	$(CXX) /c /nologo /TP /Fo$@ $(RECGUI_CXXFLAGS) .\..\..\src\rg\fb\fbRgEditMedia.cpp

recgui_fbRgEditReference.obj: .\..\..\src\rg\fb\fbRgEditReference.cpp
	$(CXX) /c /nologo /TP /Fo$@ $(RECGUI_CXXFLAGS) .\..\..\src\rg\fb\fbRgEditReference.cpp

recgui_fbRgSelect.obj: .\..\..\src\rg\fb\fbRgSelect.cpp
	$(CXX) /c /nologo /TP /Fo$@ $(RECGUI_CXXFLAGS) .\..\..\src\rg\fb\fbRgSelect.cpp

recgui_fbRgViewMedia.obj: .\..\..\src\rg\fb\fbRgViewMedia.cpp
	$(CXX) /c /nologo /TP /Fo$@ $(RECGUI_CXXFLAGS) .\..\..\src\rg\fb\fbRgViewMedia.cpp

recgui_fbRgDialog.obj: .\..\..\src\rg\fbRgDialog.cpp
	$(CXX) /c /nologo /TP /Fo$@ $(RECGUI_CXXFLAGS) .\..\..\src\rg\fbRgDialog.cpp

recgui_recgui.obj: .\..\..\src\rg\recgui.cpp
	$(CXX) /c /nologo /TP /Fo$@ $(RECGUI_CXXFLAGS) .\..\..\src\rg\recgui.cpp

recgui_rgCompareEvent.obj: .\..\..\src\rg\rgCompareEvent.cpp
	$(CXX) /c /nologo /TP /Fo$@ $(RECGUI_CXXFLAGS) .\..\..\src\rg\rgCompareEvent.cpp

recgui_rgCrDatabase.obj: .\..\..\src\rg\rgCrDatabase.cpp
	$(CXX) /c /nologo /TP /Fo$@ $(RECGUI_CXXFLAGS) .\..\..\src\rg\rgCrDatabase.cpp

recgui_rgCrIndividual.obj: .\..\..\src\rg\rgCrIndividual.cpp
	$(CXX) /c /nologo /TP /Fo$@ $(RECGUI_CXXFLAGS) .\..\..\src\rg\rgCrIndividual.cpp

recgui_rgCrName.obj: .\..\..\src\rg\rgCrName.cpp
	$(CXX) /c /nologo /TP /Fo$@ $(RECGUI_CXXFLAGS) .\..\..\src\rg\rgCrName.cpp

recgui_rgEdContact.obj: .\..\..\src\rg\rgEdContact.cpp
	$(CXX) /c /nologo /TP /Fo$@ $(RECGUI_CXXFLAGS) .\..\..\src\rg\rgEdContact.cpp

recgui_rgEdDate.obj: .\..\..\src\rg\rgEdDate.cpp
	$(CXX) /c /nologo /TP /Fo$@ $(RECGUI_CXXFLAGS) .\..\..\src\rg\rgEdDate.cpp

recgui_rgEdEvent.obj: .\..\..\src\rg\rgEdEvent.cpp
	$(CXX) /c /nologo /TP /Fo$@ $(RECGUI_CXXFLAGS) .\..\..\src\rg\rgEdEvent.cpp

recgui_rgEdEventa.obj: .\..\..\src\rg\rgEdEventa.cpp
	$(CXX) /c /nologo /TP /Fo$@ $(RECGUI_CXXFLAGS) .\..\..\src\rg\rgEdEventa.cpp

recgui_rgEdEventEventa.obj: .\..\..\src\rg\rgEdEventEventa.cpp
	$(CXX) /c /nologo /TP /Fo$@ $(RECGUI_CXXFLAGS) .\..\..\src\rg\rgEdEventEventa.cpp

recgui_rgEdEventType.obj: .\..\..\src\rg\rgEdEventType.cpp
	$(CXX) /c /nologo /TP /Fo$@ $(RECGUI_CXXFLAGS) .\..\..\src\rg\rgEdEventType.cpp

recgui_rgEdFamily.obj: .\..\..\src\rg\rgEdFamily.cpp
	$(CXX) /c /nologo /TP /Fo$@ $(RECGUI_CXXFLAGS) .\..\..\src\rg\rgEdFamily.cpp

recgui_rgEdGallery.obj: .\..\..\src\rg\rgEdGallery.cpp
	$(CXX) /c /nologo /TP /Fo$@ $(RECGUI_CXXFLAGS) .\..\..\src\rg\rgEdGallery.cpp

recgui_rgEdIndividual.obj: .\..\..\src\rg\rgEdIndividual.cpp
	$(CXX) /c /nologo /TP /Fo$@ $(RECGUI_CXXFLAGS) .\..\..\src\rg\rgEdIndividual.cpp

recgui_rgEdMedia.obj: .\..\..\src\rg\rgEdMedia.cpp
	$(CXX) /c /nologo /TP /Fo$@ $(RECGUI_CXXFLAGS) .\..\..\src\rg\rgEdMedia.cpp

recgui_rgEdName.obj: .\..\..\src\rg\rgEdName.cpp
	$(CXX) /c /nologo /TP /Fo$@ $(RECGUI_CXXFLAGS) .\..\..\src\rg\rgEdName.cpp

recgui_rgEdNamePart.obj: .\..\..\src\rg\rgEdNamePart.cpp
	$(CXX) /c /nologo /TP /Fo$@ $(RECGUI_CXXFLAGS) .\..\..\src\rg\rgEdNamePart.cpp

recgui_rgEdPerIndEvent.obj: .\..\..\src\rg\rgEdPerIndEvent.cpp
	$(CXX) /c /nologo /TP /Fo$@ $(RECGUI_CXXFLAGS) .\..\..\src\rg\rgEdPerIndEvent.cpp

recgui_rgEdPersona.obj: .\..\..\src\rg\rgEdPersona.cpp
	$(CXX) /c /nologo /TP /Fo$@ $(RECGUI_CXXFLAGS) .\..\..\src\rg\rgEdPersona.cpp

recgui_rgEdPlace.obj: .\..\..\src\rg\rgEdPlace.cpp
	$(CXX) /c /nologo /TP /Fo$@ $(RECGUI_CXXFLAGS) .\..\..\src\rg\rgEdPlace.cpp

recgui_rgEdReference.obj: .\..\..\src\rg\rgEdReference.cpp
	$(CXX) /c /nologo /TP /Fo$@ $(RECGUI_CXXFLAGS) .\..\..\src\rg\rgEdReference.cpp

recgui_rgEdRelDate.obj: .\..\..\src\rg\rgEdRelDate.cpp
	$(CXX) /c /nologo /TP /Fo$@ $(RECGUI_CXXFLAGS) .\..\..\src\rg\rgEdRelDate.cpp

recgui_rgEdResearcher.obj: .\..\..\src\rg\rgEdResearcher.cpp
	$(CXX) /c /nologo /TP /Fo$@ $(RECGUI_CXXFLAGS) .\..\..\src\rg\rgEdResearcher.cpp

recgui_rgEdRole.obj: .\..\..\src\rg\rgEdRole.cpp
	$(CXX) /c /nologo /TP /Fo$@ $(RECGUI_CXXFLAGS) .\..\..\src\rg\rgEdRole.cpp

recgui_rgEdSystem.obj: .\..\..\src\rg\rgEdSystem.cpp
	$(CXX) /c /nologo /TP /Fo$@ $(RECGUI_CXXFLAGS) .\..\..\src\rg\rgEdSystem.cpp

recgui_rgEdUser.obj: .\..\..\src\rg\rgEdUser.cpp
	$(CXX) /c /nologo /TP /Fo$@ $(RECGUI_CXXFLAGS) .\..\..\src\rg\rgEdUser.cpp

recgui_rgImagePanel.obj: .\..\..\src\rg\rgImagePanel.cpp
	$(CXX) /c /nologo /TP /Fo$@ $(RECGUI_CXXFLAGS) .\..\..\src\rg\rgImagePanel.cpp

recgui_rgIndividual.obj: .\..\..\src\rg\rgIndividual.cpp
	$(CXX) /c /nologo /TP /Fo$@ $(RECGUI_CXXFLAGS) .\..\..\src\rg\rgIndividual.cpp

recgui_rgSelect.obj: .\..\..\src\rg\rgSelect.cpp
	$(CXX) /c /nologo /TP /Fo$@ $(RECGUI_CXXFLAGS) .\..\..\src\rg\rgSelect.cpp

recgui_rgSelEvent.obj: .\..\..\src\rg\rgSelEvent.cpp
	$(CXX) /c /nologo /TP /Fo$@ $(RECGUI_CXXFLAGS) .\..\..\src\rg\rgSelEvent.cpp

recgui_rgTableCtrl.obj: .\..\..\src\rg\rgTableCtrl.cpp
	$(CXX) /c /nologo /TP /Fo$@ $(RECGUI_CXXFLAGS) .\..\..\src\rg\rgTableCtrl.cpp

recgui_rgViewMedia.obj: .\..\..\src\rg\rgViewMedia.cpp
	$(CXX) /c /nologo /TP /Fo$@ $(RECGUI_CXXFLAGS) .\..\..\src\rg\rgViewMedia.cpp

