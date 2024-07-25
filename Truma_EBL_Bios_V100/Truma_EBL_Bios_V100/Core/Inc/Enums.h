#ifndef ENUMS_H
#define ENUMS_H

#define	info_leisure_batt2      0x42  //0x02,
#define info_leisure_batt1      0xC4  //0x04,
#define ctrl_batt_properties    0x85  //0x05,
#define ctrl_switchs            0xCF  //0x0F,
#define info_switchs            0x50  //0x10,
#define ctrl_waterMng           0x11  //0x11,
#define ctrl_battMng            0x20  //0x20,
#define info_battMng            0x61  //0x21,
#define info_waterMng           0x32  //0x32,
#define info_vehicleBatt        0xFB  //0x3B
#define controller              0x3C  //0x3C
#define info_controller         0x7D  //0x3D

enum controls {off = 0, on, ignore =3};

enum infos {_off = 0, _on, _na, _ni};

#endif
