#Author: Meredith Kiessling
# Date: 10.21.2016
# Description: Makefile for Project2 - getData

CXX = g++
CXXFLAGS = -std=c++0x
SRCS = changegreedy.cpp main.cpp outputCSV.cpp
HEADERS = changegreedy.hpp outputCSV.hpp result.hpp testCase.hpp
TARGET = data

final: ${SRCS} ${HEADERS}
	${CXX} ${CXXFLAGS} ${SRCS} -o ${TARGET}
clean:
	${RM} ${TARGET}
