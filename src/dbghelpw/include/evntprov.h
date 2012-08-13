/*
 * Copyright 2010 Hans Leidekker for CodeWeavers
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA 02110-1301, USA
 */

#ifndef _EVNTPROV_H_
#define _EVNTPROV_H_

#ifdef __cplusplus
extern "C" {
#endif

#define EVENT_LEVEL_MIN 0x00
#define EVENT_LEVEL_MAX 0xff

typedef ULONGLONG REGHANDLE, *PREGHANDLE;

typedef struct _EVENT_DESCRIPTOR
{
    USHORT    Id;
    UCHAR     Version;
    UCHAR     Channel;
    UCHAR     Level;
    UCHAR     Opcode;
    USHORT    Task;
    ULONGLONG Keyword;
} EVENT_DESCRIPTOR;

typedef       EVENT_DESCRIPTOR *PEVENT_DESCRIPTOR;
typedef const EVENT_DESCRIPTOR *PCEVENT_DESCRIPTOR;

typedef struct _EVENT_FILTER_DESCRIPTOR
{
    ULONGLONG   Ptr;
    ULONG       Size;
    ULONG       Type;

} EVENT_FILTER_DESCRIPTOR, *PEVENT_FILTER_DESCRIPTOR;

typedef VOID (NTAPI *PENABLECALLBACK)(LPCGUID,ULONG,UCHAR,ULONGLONG,ULONGLONG,PEVENT_FILTER_DESCRIPTOR,PVOID);

BOOLEAN WINAPI EventEnabled(REGHANDLE, PCEVENT_DESCRIPTOR);
ULONG WINAPI EventRegister(LPCGUID,PENABLECALLBACK,PVOID,PREGHANDLE);
ULONG WINAPI EventUnregister(REGHANDLE);

#ifdef __cplusplus
}
#endif

#endif /* _EVNTPROV_H_ */
