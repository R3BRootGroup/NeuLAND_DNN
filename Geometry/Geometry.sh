#!/bin/bash

# Generates the Geometry of the simulation:

root -l -q NeuLAND_BuildGeometry.cpp
root -l -q VETO_BuildGeometry.cpp
root -l -q NEBULA_BuildGeometry.cpp
root -l -q NEBULA_VETO_BuildGeometry.cpp
root -l -q GLAD_BuildGeometry.cpp
root -l -q Build_Chamber_Dummy_Geometry.cpp
root -l -q Target_BuildGeometry.cpp
root -l -q PSP_BuildGeometry.cpp
root -l -q StarTrack_BuildGeometry.cpp
root -l -q VacuumVessel_BuildGeometry.cpp
root -l -q CALIFA_BuildGeometry.cpp
