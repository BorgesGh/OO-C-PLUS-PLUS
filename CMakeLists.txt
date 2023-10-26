cmake_minimum_required(VERSION 3.26)
project(TestandoCoisas)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(TestandoCoisas
        Tipos/Terrano/Tropas/Ambunave.h
        Tipos/Proton/Tropas/Colosso.h
        Tipos/Terrano/Tropas/CruzadorDeBatalha.h
        Tipos/Naga/Tropas/Devoradora.h
        Tipos/Naga/Tropas/Empalador.h
        Tipos/Terrano/Tropas/Endiabrado.h
        Tipos/Proton/Tropas/Fanaticus.h
        ClassesBase/Guerreiro.h
        ClassesBase/Guerreiro.cpp
        Tipos/Zerg/Tropas/Infestador.h
        main.cpp
        ClassesBase/Mecanico.h
        Tipos/Zerg/Tropas/MestreDasCastas.h
        Tipos/Zerg/Tropas/MestreDasCastas.cpp
        Tipos/Naga/Naga.h
        ClassesBase/Object.h
        ClassesBase/Organico.h
        Tipos/Proton/Proton.h
        Random.h
        Tipos/Naga/Tropas/Servo.h
        Tipos/Terrano/Tropas/Soldado.h
        Tipos/Zerg/Tropas/Tatu-Bomba.h
        Tipos/Terrano/Terrano.h
        Tipos/Proton/Tropas/Tormento.h
        Tipos/Proton/Tropas/Transportadora.h
        Tipos/Zerg/Zerg.h
        Tipos/Zerg/Tropas/Zerguinideo.h
        lado1.txt
        lado2.txt
        ClassesBase/Guerreiro.cpp
        Tipos/Proton/Tropas/CloneTormento.h
        Tipos/Proton/Tropas/Tormento.cpp

)
