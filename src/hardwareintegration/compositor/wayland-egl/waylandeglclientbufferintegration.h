/****************************************************************************
**
** Copyright (C) 2015 The Qt Company Ltd.
** Contact: http://www.qt.io/licensing/
**
** This file is part of the QtWaylandCompositor module of the Qt Toolkit.
**
** $QT_BEGIN_LICENSE:LGPL3$
** Commercial License Usage
** Licensees holding valid commercial Qt licenses may use this file in
** accordance with the commercial license agreement provided with the
** Software or, alternatively, in accordance with the terms contained in
** a written agreement between you and The Qt Company. For licensing terms
** and conditions see http://www.qt.io/terms-conditions. For further
** information use the contact form at http://www.qt.io/contact-us.
**
** GNU Lesser General Public License Usage
** Alternatively, this file may be used under the terms of the GNU Lesser
** General Public License version 3 as published by the Free Software
** Foundation and appearing in the file LICENSE.LGPLv3 included in the
** packaging of this file. Please review the following information to
** ensure the GNU Lesser General Public License version 3 requirements
** will be met: https://www.gnu.org/licenses/lgpl.html.
**
** GNU General Public License Usage
** Alternatively, this file may be used under the terms of the GNU
** General Public License version 2.0 or later as published by the Free
** Software Foundation and appearing in the file LICENSE.GPL included in
** the packaging of this file. Please review the following information to
** ensure the GNU General Public License version 2.0 requirements will be
** met: http://www.gnu.org/licenses/gpl-2.0.html.
**
** $QT_END_LICENSE$
**
****************************************************************************/

#ifndef WAYLANDEGLINTEGRATION_H
#define WAYLANDEGLINTEGRATION_H

#include <QtWaylandCompositor/private/qwlclientbufferintegration_p.h>
#include <QtCore/QScopedPointer>
#include <QtWaylandCompositor/private/qwlclientbuffer_p.h>

QT_BEGIN_NAMESPACE

class WaylandEglClientBufferIntegrationPrivate;

class WaylandEglClientBufferIntegration : public QtWayland::ClientBufferIntegration
{
    Q_DECLARE_PRIVATE(WaylandEglClientBufferIntegration)
public:
    WaylandEglClientBufferIntegration();

    void initializeHardware(struct ::wl_display *display) Q_DECL_OVERRIDE;

    QtWayland::ClientBuffer *createBufferFor(wl_resource *buffer);

private:
    Q_DISABLE_COPY(WaylandEglClientBufferIntegration)
    QScopedPointer<WaylandEglClientBufferIntegrationPrivate> d_ptr;
};

struct BufferState;

class WaylandEglClientBuffer : public QtWayland::ClientBuffer
{
public:
    QWaylandBufferRef::BufferFormatEgl bufferFormatEgl() const Q_DECL_OVERRIDE;
    QSize size() const Q_DECL_OVERRIDE;
    QWaylandSurface::Origin origin() const Q_DECL_OVERRIDE;
    quintptr lockNativeBuffer() Q_DECL_OVERRIDE;
    void unlockNativeBuffer(quintptr native_buffer) const Q_DECL_OVERRIDE;
    QOpenGLTexture *toOpenGlTexture(int plane) Q_DECL_OVERRIDE;
    void setCommitted(QRegion &damage) Q_DECL_OVERRIDE;

private:
    friend class WaylandEglClientBufferIntegration;
    friend class WaylandEglClientBufferIntegrationPrivate;

    WaylandEglClientBuffer(WaylandEglClientBufferIntegration* integration, wl_resource *bufferResource);

    BufferState *d;
    WaylandEglClientBufferIntegration *m_integration;
};

QT_END_NAMESPACE

#endif // WAYLANDEGLINTEGRATION_H
