/*
 * Copyright (C) 2018 Red Hat
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License as
 * published by the Free Software Foundation; either version 2 of the
 * License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA
 * 02111-1307, USA.
 */

#ifndef META_KMS_PLANE_H
#define META_KMS_PLANE_H

#include <glib-object.h>
#include <stdint.h>
#include <xf86drmMode.h>

#include "backends/native/meta-kms-types.h"
#include "backends/meta-monitor-transform.h"

typedef enum _MetaKmsPlaneType
{
  META_KMS_PLANE_TYPE_PRIMARY,
  META_KMS_PLANE_TYPE_CURSOR,
  META_KMS_PLANE_TYPE_OVERLAY,
} MetaKmsPlaneType;

#define META_TYPE_KMS_PLANE meta_kms_plane_get_type ()
G_DECLARE_FINAL_TYPE (MetaKmsPlane, meta_kms_plane,
                      META, KMS_PLANE, GObject)

MetaKmsPlane * meta_kms_plane_new (MetaKmsPlaneType         type,
                                   MetaKmsImplDevice       *impl_device,
                                   drmModePlane            *drm_plane,
                                   drmModeObjectProperties *drm_plane_props);

MetaKmsPlaneType meta_kms_plane_get_plane_type (MetaKmsPlane *plane);

gboolean meta_kms_plane_is_transform_handled (MetaKmsPlane         *plane,
                                              MetaMonitorTransform  transform);

gboolean meta_kms_plane_is_usable_with (MetaKmsPlane *plane,
                                        MetaKmsCrtc  *crtc);

#endif /* META_KMS_PLANE_H */