#include <iostream>
#include <string>

using namespace std;

int main()
{
    // Menü anzeigen und Benutzerauswahl verarbeiten
    string input;
    cout << "Ver- oder Entschlüsseln? (v/e) ";
    getline(cin, input);

    bool encode;
    if (input == "v")
    {
        // VERschlüsseln aktivieren
        encode = true;
    }
    else if (input == "e")
    {
        // ENTschlüsseln aktivieren
        encode = false;
    }
    else
    {
        cout << "Ungültige Eingabe!" << endl;
        exit(EXIT_FAILURE); // Fehlercode melden
    }

    // Text zum Ver- oder Entschlüsseln einlesen
    string output;
    cout << "Nachricht eingeben: ";
    getline(cin, input);

    // ERWEITERUNG: DYNAMISCHE CAESAR-ZAHL
    int caesar;
    // 1. Benutzereingabe für Caesar-Zahl
    cout << "Gebe eine Caesar-Zahl im Bereich von 1 bis 94 ein: ";
    cin >> caesar;

    // Zeichenweise Ver- bzw. Entschlüsselung
    int cnt = 0;
    while (cnt < input.size())
    {
        // Symbol zu Zahl umwandeln
        int ascii = (int)input[cnt];

        // ERWEITERUNG: SPEZIELLE ZEICHENBEHANDLUNG
        if (ascii <= 32 || ascii >= 127)
        {
            output.push_back(input[cnt]);
            cnt++;
            continue;
        }

        // Zahl um festen Wert verschieben
        int res;
        if (encode == true) // Verschlüsseln
        {
            res = (ascii + caesar - 33) % 94 + 33;
        }
        else // Entschlüsseln
        {
            res = (ascii - caesar - 33 + 94) % 94 + 33;
        }

        // Zahl zu Symbol rückwandeln
        char code = (char)res;

        // Neuen Symbol an Ergebnis anhängen
        output.push_back(code);

        cnt++;
    }
    cout << "Nachricht: " << output << endl;

    return EXIT_SUCCESS;
}