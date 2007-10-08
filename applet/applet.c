/*
 * keyboard - Tray applet to toggle matchbox-keyboard's visibility
 *
 * Copyright (C) 2007 OpenedHand Ltd.
 *
 * Authors:
 *  Ross Burton <ross@openedhand.com>
 *  Stefan Schmidt <stefan@openmoko.org>
 *
 * This program is free software; you can redistribute it and/or modify it under
 * the terms of the GNU General Public License as published by the Free Software
 * Foundation; version 2 of the license.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
 * FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more
 * details.
 */

#include <gtk/gtk.h>
#include <matchbox-panel/mb-panel.h>
#include <matchbox-panel/mb-panel-scaling-image.h>
#include <gtk-im/im-protocol.h>

static void
on_toggled (GtkWidget *event_box, GdkEventButton *event, gpointer user_data)
{
  protocol_send_event (INVOKE_KBD_TOGGLE);
}

G_MODULE_EXPORT GtkWidget *
mb_panel_applet_create (const char *id, GtkOrientation orientation)
{
  GtkWidget *box, *image;

  box = gtk_event_box_new ();
  gtk_event_box_set_visible_window (GTK_EVENT_BOX (box), FALSE);
  gtk_widget_set_name (box, "MatchboxPanelKeyboard");

  image = mb_panel_scaling_image_new (orientation, "matchbox-keyboard");
  gtk_container_add (GTK_CONTAINER (box), image);

  g_signal_connect (box, "button-release-event", G_CALLBACK (on_toggled), NULL);

  gtk_widget_show_all (box);

  return box;
}
