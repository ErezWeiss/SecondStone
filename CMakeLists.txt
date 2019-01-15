cmake_minimum_required(VERSION 3.12)
project(SecondStone)

set(CMAKE_CXX_STANDARD 14)
SET(CMAKE_CXX_FLAGS -pthread)

add_executable(SecondStone StringReverser.cpp StringReverser.h StringReverseCH.h StringReverseCH.cpp Solver.h main.cpp MyParallelServer.cpp MyParallelServer.h ClientHandler.h MyTestClientHandler.cpp MyTestClientHandler.h MySerialServer.cpp MySerialServer.h MyClientHandler.cpp MyClientHandler.h Matrix.cpp Matrix.h SearcherAdapter.cpp SearcherAdapter.h State.h absSearch.h MatrixBuilder.cpp MatrixBuilder.h SearchableMatrix.cpp SearchableMatrix.h Point.cpp Point.h VectorMakerFromStrings.cpp VectorMakerFromStrings.h BestFirstSearch.cpp BestFirstSearch.h absSearch.h)
