/*
 * Copyright (C) 2016-2020 Red Hat
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
 *
 */

#ifndef META_ONSCREEN_NATIVE_H
#define META_ONSCREEN_NATIVE_H

#include <glib.h>

#include "backends/meta-backend-types.h"
#include "backends/native/meta-backend-native-types.h"
#include "clutter/clutter.h"
#include "cogl/cogl.h"

gboolean
meta_renderer_native_init_onscreen (CoglOnscreen *onscreen,
                                    GError      **error);

void meta_renderer_native_release_onscreen (CoglOnscreen *onscreen);

gboolean meta_onscreen_native_allocate (CoglOnscreen *onscreen,
                                        GError      **error);

void meta_onscreen_native_swap_buffers_with_damage (CoglOnscreen  *onscreen,
                                                    const int     *rectangles,
                                                    int            n_rectangles,
                                                    CoglFrameInfo *frame_info,
                                                    gpointer       user_data);

gboolean meta_onscreen_native_direct_scanout (CoglOnscreen   *onscreen,
                                              CoglScanout    *scanout,
                                              CoglFrameInfo  *frame_info,
                                              gpointer        user_data,
                                              GError        **error);

void meta_onscreen_native_finish_frame (CoglOnscreen *onscreen,
                                        ClutterFrame *frame);

void meta_onscreen_native_notify_mode_set_failed (CoglOnscreen *onscreen);

void meta_onscreen_native_dummy_power_save_page_flip (CoglOnscreen *onscreen);

MetaCrtc * meta_onscreen_native_get_crtc (CoglOnscreen *onscreen);

MetaRendererNative * meta_onscreen_native_get_renderer (CoglOnscreen *onscreen);

void meta_onscreen_native_set_view (CoglOnscreen     *onscreen,
                                    MetaRendererView *view);

CoglOnscreen * meta_onscreen_native_new (MetaRendererNative  *renderer_native,
                                         MetaGpuKms          *render_gpu,
                                         MetaOutput          *output,
                                         MetaCrtc            *crtc,
                                         CoglContext         *cogl_context,
                                         int                  width,
                                         int                  height,
                                         GError             **error);

#endif /* META_ONSCREEN_NATIVE_H */
