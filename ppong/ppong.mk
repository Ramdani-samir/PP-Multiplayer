##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Debug
ProjectName            :=ppong
ConfigurationName      :=Debug
WorkspacePath          :=/home/simon/Bureau/game
ProjectPath            :=/home/simon/Bureau/game/ppong
IntermediateDirectory  :=./Debug
OutDir                 := $(IntermediateDirectory)
CurrentFileName        :=
CurrentFilePath        :=
CurrentFileFullPath    :=
User                   :=Simon
Date                   :=12/31/20
CodeLitePath           :=/home/simon/.codelite
LinkerName             :=/usr/bin/g++ -lpthread
SharedObjectLinkerName :=/usr/bin/g++ -shared -fPIC -lpthread
ObjectSuffix           :=.o
DependSuffix           :=.o.d
PreprocessSuffix       :=.i
DebugSwitch            :=-g 
IncludeSwitch          :=-I
LibrarySwitch          :=-l
OutputSwitch           :=-o 
LibraryPathSwitch      :=-L
PreprocessorSwitch     :=-D
SourceSwitch           :=-c 
OutputFile             :=$(IntermediateDirectory)/$(ProjectName)
Preprocessors          :=
ObjectSwitch           :=-o 
ArchiveOutputSwitch    := 
PreprocessOnlySwitch   :=-E
ObjectsFileList        :="ppong.txt"
PCHCompileFlags        :=
MakeDirCommand         :=mkdir -p
LinkOptions            := -lsqlite3 -lpthread -std=c++11 
IncludePath            :=  $(IncludeSwitch). $(IncludeSwitch). 
IncludePCH             := 
RcIncludePath          := 
Libs                   := 
ArLibs                 :=  
LibPath                := $(LibraryPathSwitch). 

##
## Common variables
## AR, CXX, CC, AS, CXXFLAGS and CFLAGS can be overriden using an environment variables
##
AR       := /usr/bin/ar rcu
CXX      := /usr/bin/g++ -lpthread
CC       := /usr/bin/gcc
CXXFLAGS := -lsqlite3 -lpthread -std=c++11 -g -O0 -Wall $(Preprocessors)
CFLAGS   :=  -g -O0 -Wall $(Preprocessors)
ASFLAGS  := 
AS       := /usr/bin/as


##
## User defined environment variables
##
CodeLiteDir:=/usr/share/codelite
Objects0=$(IntermediateDirectory)/main.cpp$(ObjectSuffix) $(IntermediateDirectory)/score.cpp$(ObjectSuffix) $(IntermediateDirectory)/TCP.cpp$(ObjectSuffix) $(IntermediateDirectory)/Streamer.cpp$(ObjectSuffix) 



Objects=$(Objects0) 

##
## Main Build Targets 
##
.PHONY: all clean PreBuild PrePreBuild PostBuild MakeIntermediateDirs
all: $(OutputFile)

$(OutputFile): $(IntermediateDirectory)/.d $(Objects) 
	@$(MakeDirCommand) $(@D)
	@echo "" > $(IntermediateDirectory)/.d
	@echo $(Objects0)  > $(ObjectsFileList)
	$(LinkerName) $(OutputSwitch)$(OutputFile) @$(ObjectsFileList) $(LibPath) $(Libs) $(LinkOptions)

MakeIntermediateDirs:
	@test -d ./Debug || $(MakeDirCommand) ./Debug


$(IntermediateDirectory)/.d:
	@test -d ./Debug || $(MakeDirCommand) ./Debug

PreBuild:


##
## Objects
##
$(IntermediateDirectory)/main.cpp$(ObjectSuffix): main.cpp $(IntermediateDirectory)/main.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/simon/Bureau/game/ppong/main.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/main.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/main.cpp$(DependSuffix): main.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/main.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/main.cpp$(DependSuffix) -MM main.cpp

$(IntermediateDirectory)/main.cpp$(PreprocessSuffix): main.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/main.cpp$(PreprocessSuffix) main.cpp

$(IntermediateDirectory)/score.cpp$(ObjectSuffix): score.cpp $(IntermediateDirectory)/score.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/simon/Bureau/game/ppong/score.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/score.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/score.cpp$(DependSuffix): score.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/score.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/score.cpp$(DependSuffix) -MM score.cpp

$(IntermediateDirectory)/score.cpp$(PreprocessSuffix): score.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/score.cpp$(PreprocessSuffix) score.cpp

$(IntermediateDirectory)/TCP.cpp$(ObjectSuffix): TCP.cpp $(IntermediateDirectory)/TCP.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/simon/Bureau/game/ppong/TCP.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/TCP.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/TCP.cpp$(DependSuffix): TCP.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/TCP.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/TCP.cpp$(DependSuffix) -MM TCP.cpp

$(IntermediateDirectory)/TCP.cpp$(PreprocessSuffix): TCP.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/TCP.cpp$(PreprocessSuffix) TCP.cpp

$(IntermediateDirectory)/Streamer.cpp$(ObjectSuffix): Streamer.cpp $(IntermediateDirectory)/Streamer.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/simon/Bureau/game/ppong/Streamer.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Streamer.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Streamer.cpp$(DependSuffix): Streamer.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Streamer.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Streamer.cpp$(DependSuffix) -MM Streamer.cpp

$(IntermediateDirectory)/Streamer.cpp$(PreprocessSuffix): Streamer.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Streamer.cpp$(PreprocessSuffix) Streamer.cpp


-include $(IntermediateDirectory)/*$(DependSuffix)
##
## Clean
##
clean:
	$(RM) -r ./Debug/


