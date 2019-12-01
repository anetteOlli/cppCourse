#include <gtkmm.h>
#include <string>

//Assigment 4, gtkmm-example

/*
Ta utgangspunkt i https://gitlab.com/ntnu-iini4003/gtkmm-example og lag eit lite program som slår sammen inntastet fornavn og etternavn når du klikker på en knapp. Knappen skal kun være sensitiv når både fornavn og etternavn er tastet inn, og grået ut ellers (ikke sensitiv). Sett også tittel på vinduet. To eksempler på hvordan programmet kan se ut er vist under:
*/

class Window : public Gtk::Window {
public:
  Gtk::VBox vbox;
  Gtk::Entry firstname;
  Gtk::Entry surname;
  Gtk::Button button;
  Gtk::Label label;
  Gtk::Label firstname_label;
  Gtk::Label surname_label;
  std::string firstname_string;
  std::string surname_string;

  Window() {
    firstname_string = " ";
    surname_string = " ";
    firstname.set_tooltip_text("first name");
    firstname_label.set_text("first name:");
    surname_label.set_text("last name");
    button.set_label("Combine names");
    vbox.pack_start(firstname_label);
    vbox.pack_start(firstname);  //Add the widget entry to vboxAleksander
    vbox.pack_start(surname_label);
    vbox.pack_start(surname);
    vbox.pack_start(button); //Add the widget button to vbox
    vbox.pack_start(label);  //Add the widget label to vbox


    add(vbox);  //Add vbox to window
    show_all(); //Show all widgetsf

    button.set_sensitive(false);

    firstname.signal_changed().connect([this]() {
        firstname_string = firstname.get_text();
        if (surname_string.size() > 2 && firstname_string.size() > 2) {
            button.set_sensitive(true);
       }else {
            button.set_sensitive(false);
        }
    });

    surname.signal_changed().connect([this]() {
        surname_string = surname.get_text();
        if (surname_string.size() > 2 && firstname_string.size() > 2) {
            button.set_sensitive(true);
        }else {
            button.set_sensitive(false);
        }
    });

    button.signal_clicked().connect([this]() {
        std::string full_name = firstname_string + " " + surname_string;
      label.set_text(full_name);
    });
  }
};

int main() {
  Gtk::Main gtk_main;
  Window window;
  gtk_main.run(window);
}
