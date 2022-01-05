cmake_minimum_required(VERSION 3.21)
project(Finite_state_tool)

set(CMAKE_CXX_STANDARD 14)

include_directories(Automation_base)
include_directories(Collections)
include_directories(Collections/CustomSet)
include_directories(CommandShell/Commands)
include_directories(CommandShell/Dispatcher)
include_directories(Environment)
include_directories(Finate_state_automation)
include_directories(GraphVisualizationTool)
include_directories(MinimalAcyclicSubsequentialTransducer)
include_directories(MinimalAcyclicSubsequentialTransducer/AcyclicSubsequentialTransducer)
include_directories(MinimalAcyclicSubsequentialTransducer/Builder)
include_directories(Non-deterministic_pushdown_automaton)
add_executable(main main.cpp)
file(GLOB_RECURSE SRC_LIST *.cpp)
add_library(SRC ${SRC_LIST})
target_link_libraries(main SRC)
#add_executable(Finite_state_tool
#        Automation_base/AutomationBase.cpp
#        Automation_base/AutomationBase.h
#        Collections/CustomSet/CustomSet.hpp
#        CommandShell/Commands/Commands.cpp
#        CommandShell/Commands/Commands.h
#        CommandShell/Dispatcher/CommandDispatcher.cpp
#        CommandShell/Dispatcher/CommandDispatcher.h
#        Environment/AFL_Environment.cpp
#        Environment/AFL_Environment.h
#        Finate_state_automation/FiniteStateAutomation.cpp
#        Finate_state_automation/FiniteStateAutomation.h
#        GraphVisualizationTool/GraphVisualiser.cpp
#        GraphVisualizationTool/GraphVisualiser.h
#        MinimalAcyclicSubsequentialTransducer/AcyclicSubsequentialTransducer/SubsequentialTransducer.cpp
#        MinimalAcyclicSubsequentialTransducer/AcyclicSubsequentialTransducer/SubsequentialTransducer.h
#        MinimalAcyclicSubsequentialTransducer/Builder/MinimalSubsequentialTransducerBuilder.cpp
#        MinimalAcyclicSubsequentialTransducer/Builder/MinimalSubsequentialTransducerBuilder.h
#        MinimalAcyclicSubsequentialTransducer/FilesUtills.h
#        MinimalAcyclicSubsequentialTransducer/Source.cpp
#        Non-deterministic_pushdown_automaton/NPDA.cpp
#        Non-deterministic_pushdown_automaton/NPDA.h
#        Tests/tests.cpp
#        main.cpp)
