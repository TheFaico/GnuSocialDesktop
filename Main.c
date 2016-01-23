/*
 * Copyright (C) 2016 Dan Rulos.
 * 
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include <gtk/gtk.h>
#include <string.h>
#include "update_status.h"
#include "lang/spanish.h"

gint delete_event( GtkWidget *widget,
                   GdkEvent  *event,
                   gpointer   data )
{
    gtk_main_quit();
    return(FALSE);
}

GtkWidget *entry[4], *window;

GtkWidget *quit_message_entry;

void run_update_status(GtkWidget *button1, char data[5][32])
{
	update_status(quit_message_entry, data);
	gtk_widget_destroy(window);
	gtk_main_quit();
}

void send_quit()
{
	GtkWidget *table, *label1;
	window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
	gtk_window_set_title (GTK_WINDOW (window), MSG_7);
    	gtk_signal_connect (GTK_OBJECT (window), "delete_event",
        GTK_SIGNAL_FUNC (delete_event), NULL);
	table = gtk_table_new(3,2,FALSE);
	gtk_container_add(GTK_CONTAINER(window),table);
	label1 = gtk_label_new(MSG_8);
	gtk_table_attach_defaults(GTK_TABLE(table),label1,0,1,0,1);
	quit_message_entry = gtk_entry_new();
	gtk_table_attach_defaults(GTK_TABLE(table),quit_message_entry,1,2,0,1);
	gtk_entry_set_visibility(GTK_ENTRY(quit_message_entry),TRUE);
	char data[5][32];
	for (int i = 0; i < 4; i++) {
		char *p = gtk_entry_get_text(entry[i]);
		strcpy(data[i], p);
	}
	GtkWidget *button1 = gtk_button_new_with_label (MSG_9);
	gtk_signal_connect (GTK_OBJECT (button1), "clicked", GTK_SIGNAL_FUNC (run_update_status), (gpointer) data);
	gtk_box_pack_start(GTK_BOX(table), button1, TRUE, TRUE, 0);
	gtk_table_attach_defaults(GTK_TABLE(table),button1,1,2,1,2);
	//g_signal_connect(G_OBJECT(entry1),"activate",G_CALLBACK(run_update_status),data);
	gtk_container_add(GTK_CONTAINER(window),table);
        gtk_widget_show_all(window);
        gtk_main();
}

void about_me()
{
	GtkWidget *dialog, *label;
	GdkPixbuf *pixbuf;
	GtkWidget *picture;

	dialog = gtk_dialog_new_with_buttons (MSG_2,
		GTK_WINDOW (window),
		GTK_DIALOG_DESTROY_WITH_PARENT,
		GTK_STOCK_OK,
		GTK_RESPONSE_NONE,
		NULL);
	label = gtk_label_new ("\t\t\tGnuSocial Desktop v0.2\n\tGSD es un sencillo cliente de la Red Social Libre\
		\nGNUSocial escrito en C y GTK por <dalmemail@amaya.tk>\n\t\t\thttp://gsdesktop.amayaos.com");

	pixbuf = gdk_pixbuf_new_from_file_at_scale("logo.png",175,55,FALSE,NULL);
	picture=gtk_image_new_from_pixbuf(pixbuf);
	gtk_container_add(GTK_CONTAINER (GTK_DIALOG(dialog)->vbox), picture);

	g_signal_connect_swapped (GTK_OBJECT (dialog),
		"response",
		G_CALLBACK (gtk_widget_destroy),
		GTK_OBJECT (dialog));
	gtk_container_add (GTK_CONTAINER (GTK_DIALOG(dialog)->vbox),
		label);
	gtk_widget_show_all (dialog);
}

int main(int argc, char **argv)
{
	GdkPixbuf *pixbuf;
	GtkWidget *picture;
        GtkWidget *w, *box1;
	GtkWidget *button1, *button2;
	GtkWidget *label1, *label2, *label3, *label4;

        gtk_init(&argc, &argv);

        /* Creo la ventana */
        w = gtk_window_new(GTK_WINDOW_TOPLEVEL);

        /* Le pongo un título */
        gtk_window_set_title(GTK_WINDOW(w), "GSD");
    	gtk_signal_connect (GTK_OBJECT (w), "delete_event",
        GTK_SIGNAL_FUNC (delete_event), NULL);
	box1 = gtk_table_new(3,2,FALSE);

        /* Cargamos el logo. */
	pixbuf = gdk_pixbuf_new_from_file_at_scale("logo.png",350,110,FALSE,NULL);
	picture=gtk_image_new_from_pixbuf(pixbuf);
	gtk_table_attach_defaults(GTK_TABLE(box1),picture,0,2,0,1);

	/* Botón 1 */
	button1 = gtk_button_new_with_label (MSG_1);
	gtk_signal_connect (GTK_OBJECT (button1), "clicked", GTK_SIGNAL_FUNC (send_quit), (gpointer) "button 1");
	gtk_box_pack_start(GTK_BOX(box1), button1, TRUE, TRUE, 0);
	gtk_table_attach_defaults(GTK_TABLE(box1),button1,0,1,9,10);

	button2 = gtk_button_new_with_label (MSG_2);
	gtk_signal_connect (GTK_OBJECT (button2), "clicked", GTK_SIGNAL_FUNC (about_me), (gpointer) "button 1");
	gtk_box_pack_start(GTK_BOX(box1), button2, TRUE, TRUE, 0);
	gtk_table_attach_defaults(GTK_TABLE(box1),button2,1,2,9,10);

	label1 = gtk_label_new(MSG_3);
	gtk_table_attach_defaults(GTK_TABLE(box1),label1,0,1,2,3);
	entry[0] = gtk_entry_new();
	gtk_entry_set_visibility(GTK_ENTRY(entry[0]),TRUE);
	gtk_table_attach_defaults(GTK_TABLE(box1),entry[0],1,2,2,3);

	label2 = gtk_label_new(MSG_4);
	gtk_table_attach_defaults(GTK_TABLE(box1),label2,0,1,3,4);
	entry[1] = gtk_entry_new();
	gtk_entry_set_visibility(GTK_ENTRY(entry[1]),TRUE);
	gtk_table_attach_defaults(GTK_TABLE(box1),entry[1],1,2,3,4);

	label3 = gtk_label_new(MSG_5);
	gtk_table_attach_defaults(GTK_TABLE(box1),label3,0,1,5,6);
	entry[2] = gtk_entry_new();
	gtk_entry_set_visibility(GTK_ENTRY(entry[2]),TRUE);
	gtk_table_attach_defaults(GTK_TABLE(box1),entry[2],1,2,5,6);

	label4 = gtk_label_new(MSG_6);
	gtk_table_attach_defaults(GTK_TABLE(box1),label4,0,1,7,8);
	entry[3] = gtk_entry_new();
	gtk_entry_set_visibility(GTK_ENTRY(entry[3]),FALSE);
	gtk_table_attach_defaults(GTK_TABLE(box1),entry[3],1,2,7,8);

	gtk_container_add(GTK_CONTAINER(w), box1);

	gtk_widget_show(box1);
        gtk_widget_show_all(w);
        /* Finalmente entramos en el bucle principal. */
        gtk_main();

        return 0;
}
