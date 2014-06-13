##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Debug
ProjectName            :=Battleship
ConfigurationName      :=Debug
WorkspacePath          := "/home/lawrence/Desktop/Link to CCSF/CS110B(Code)/Battleship"
ProjectPath            := "/home/lawrence/Desktop/Link to CCSF/CS110B(Code)/Battleship"
IntermediateDirectory  :=./Debug
OutDir                 := $(IntermediateDirectory)
CurrentFileName        :=
CurrentFilePath        :=
CurrentFileFullPath    :=
User                   :=Lawrence
Date                   :=06/13/14
CodeLitePath           :="/home/lawrence/.codelite"
LinkerName             :=/usr/bin/g++ 
SharedObjectLinkerName :=/usr/bin/g++ -shared -fPIC
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
ObjectsFileList        :="Battleship.txt"
PCHCompileFlags        :=
MakeDirCommand         :=mkdir -p
LinkOptions            :=  
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
CXX      := /usr/bin/g++ 
CC       := /usr/bin/gcc 
CXXFLAGS :=  -g -O0 -Wall $(Preprocessors)
CFLAGS   :=  -g -O0 -Wall $(Preprocessors)
ASFLAGS  := 
AS       := /usr/bin/as 


##
## User defined environment variables
##
CodeLiteDir:=/usr/share/codelite
Objects0=$(IntermediateDirectory)/Board.cpp$(ObjectSuffix) $(IntermediateDirectory)/PointCollection.cpp$(ObjectSuffix) $(IntermediateDirectory)/Ship.cpp$(ObjectSuffix) $(IntermediateDirectory)/testMain.cpp$(ObjectSuffix) 



Objects=$(Objects0) 

##
## Main Build Targets 
##
.PHONY: all clean PreBuild PrePreBuild PostBuild
all: $(OutputFile)

$(OutputFile): $(IntermediateDirectory)/.d $(Objects) 
	@$(MakeDirCommand) $(@D)
	@echo "" > $(IntermediateDirectory)/.d
	@echo $(Objects0)  > $(ObjectsFileList)
	$(LinkerName) $(OutputSwitch)$(OutputFile) @$(ObjectsFileList) $(LibPath) $(Libs) $(LinkOptions)

$(IntermediateDirectory)/.d:
	@test -d ./Debug || $(MakeDirCommand) ./Debug

PreBuild:


##
## Objects
##
$(IntermediateDirectory)/Board.cpp$(ObjectSuffix): Board.cpp $(IntermediateDirectory)/Board.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/lawrence/Desktop/Link to CCSF/CS110B(Code)/Battleship/Board.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Board.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Board.cpp$(DependSuffix): Board.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Board.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Board.cpp$(DependSuffix) -MM "Board.cpp"

$(IntermediateDirectory)/Board.cpp$(PreprocessSuffix): Board.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Board.cpp$(PreprocessSuffix) "Board.cpp"

$(IntermediateDirectory)/PointCollection.cpp$(ObjectSuffix): PointCollection.cpp $(IntermediateDirectory)/PointCollection.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/lawrence/Desktop/Link to CCSF/CS110B(Code)/Battleship/PointCollection.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/PointCollection.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/PointCollection.cpp$(DependSuffix): PointCollection.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/PointCollection.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/PointCollection.cpp$(DependSuffix) -MM "PointCollection.cpp"

$(IntermediateDirectory)/PointCollection.cpp$(PreprocessSuffix): PointCollection.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/PointCollection.cpp$(PreprocessSuffix) "PointCollection.cpp"

$(IntermediateDirectory)/Ship.cpp$(ObjectSuffix): Ship.cpp $(IntermediateDirectory)/Ship.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/lawrence/Desktop/Link to CCSF/CS110B(Code)/Battleship/Ship.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Ship.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Ship.cpp$(DependSuffix): Ship.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Ship.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Ship.cpp$(DependSuffix) -MM "Ship.cpp"

$(IntermediateDirectory)/Ship.cpp$(PreprocessSuffix): Ship.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Ship.cpp$(PreprocessSuffix) "Ship.cpp"

$(IntermediateDirectory)/testMain.cpp$(ObjectSuffix): testMain.cpp $(IntermediateDirectory)/testMain.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/lawrence/Desktop/Link to CCSF/CS110B(Code)/Battleship/testMain.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/testMain.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/testMain.cpp$(DependSuffix): testMain.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/testMain.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/testMain.cpp$(DependSuffix) -MM "testMain.cpp"

$(IntermediateDirectory)/testMain.cpp$(PreprocessSuffix): testMain.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/testMain.cpp$(PreprocessSuffix) "testMain.cpp"


-include $(IntermediateDirectory)/*$(DependSuffix)
##
## Clean
##
clean:
	$(RM) $(IntermediateDirectory)/Board.cpp$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/Board.cpp$(DependSuffix)
	$(RM) $(IntermediateDirectory)/Board.cpp$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/PointCollection.cpp$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/PointCollection.cpp$(DependSuffix)
	$(RM) $(IntermediateDirectory)/PointCollection.cpp$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/Ship.cpp$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/Ship.cpp$(DependSuffix)
	$(RM) $(IntermediateDirectory)/Ship.cpp$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/testMain.cpp$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/testMain.cpp$(DependSuffix)
	$(RM) $(IntermediateDirectory)/testMain.cpp$(PreprocessSuffix)
	$(RM) $(OutputFile)
	$(RM) ".build-debug/Battleship"


