cmake_minimum_required(VERSION 3.12)
project(SecondStone)

set(CMAKE_CXX_STANDARD 14)
SET(CMAKE_CXX_FLAGS -pthread)

add_executable(SecondStone DFS.h CacheManager.h FileCacheManager.h Searcher.h StringReverser.cpp StringReverser.h Solver.h main.cpp MyParallelServer.cpp MyParallelServer.h ClientHandler.h MyTestClientHandler.cpp MyTestClientHandler.h MySerialServer.cpp MySerialServer.h MyClientHandler.cpp MyClientHandler.h SearcherAdapter.cpp SearcherAdapter.h State.h absSearch.h BFS.h MatrixBuilder.cpp MatrixBuilder.h SearchableMatrix.h Point.cpp Point.h VectorMakerFromStrings.h BestFirstSearch.h absSearch.h Astar.h)
