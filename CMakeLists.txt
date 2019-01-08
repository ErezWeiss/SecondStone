cmake_minimum_required(VERSION 3.12)
project(SecondStone)

set(CMAKE_CXX_STANDARD 14)

add_executable(ClientHandler.h SecondStone main.cpp MyTestClientHandler.cpp MyTestClientHandler.h MySerialServer.cpp MySerialServer.h Solver.h FileCacheManager.cpp FileCacheManager.h Server.h ClientHandler.h CacheManager.h StringReverser.cpp StringReverser.h Searchable.h Searcher.h DFS.cpp DFS.h BFS.cpp BFS.h HillClimbing.cpp HillClimbing.h AStar.cpp AStar.h BestFirstSearch.cpp BestFirstSearch.h StringReverseCH.cpp StringReverseCH.h)