/* bzflag
 * Copyright (c) 1993-2020 Tim Riker
 *
 * This package is free software;  you can redistribute it and/or
 * modify it under the terms of the license found in the file
 * named COPYING that should have accompanied this file.
 *
 * THIS PACKAGE IS PROVIDED ``AS IS'' AND WITHOUT ANY EXPRESS OR
 * IMPLIED WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
 */

/* XIJoystick:
 *  Encapsulates an XInput joystick
 */

#ifndef BZF_XIJOY_H
#define BZF_XIJOY_H

#include "BzfJoystick.h"
#include <X11/extensions/XInput.h>
#include <vector>
#include <string>

class XIJoystick : public BzfJoystick
{
public:
    XIJoystick();
    ~XIJoystick();

    void    initJoystick(const char* joystickName);
    bool    joystick() const;
    void    getJoy(int& x, int& y);
    unsigned long getJoyButtons();
    void    getJoyDevices(std::vector<std::string> &list) const;

private:
    Display*        display;

    XDevice*        device;
    int         scaleX, constX;
    int         scaleY, constY;

    XDeviceInfo*    devices;
    int         ndevices;

    // are these necessary?
    int         buttonPressType;
    int         buttonReleaseType;
};

#endif // BZF_XIJOY_H

// Local Variables: ***
// mode: C++ ***
// tab-width: 4 ***
// c-basic-offset: 4 ***
// indent-tabs-mode: nil ***
// End: ***
// ex: shiftwidth=4 tabstop=4
