//
//-----------------------------------------------------------------------------
//Filename:    Component.cpp
//-----------------------------------------------------------------------------
//
// Created by bonett_w on 1/11/18.
//-----------------------------------------------------------------------------
//

#include "Component.hpp"

bool engine::core::Component::Active(void) const {
    return _isActive;
}