#include <string>
#include <iostream>
#include "item.h"
#include "task.h"
#include "note.h"
#include "goal.h"
#include "habit.h"
#include "date.h"
#include "calendar.h"
#include "printer.h"
#include "console_printer.h"
#include "file_printer.h"
#include "memory_printer.h"
#include "cvector.h"
#include "sort.h"

using namespace std;
using ItemList = CVector<Item*>; 

void freeAll(ItemList& items) {
    for (auto i = 0; i < items.size(); i++) {
        delete items[i];
    }
}

int main() {
    Date today = {27, 6, 2026};
    ConsolePrinter console;

    ST taskTitle, subtask1, subtask2;
    console.printLine("=== Ingresa tu Tarea ===");
    cout << "Titulo de la tarea: ";
    getline(cin, taskTitle);
    cout << "Subtarea 1: ";
    getline(cin, subtask1);
    cout << "Subtarea 2: ";
    getline(cin, subtask2);

    Task* proyecto = new Task(taskTitle, 1);
    proyecto->addSubtask(new Task(subtask1, 2));
    proyecto->addSubtask(new Task(subtask2, 2));
    proyecto->markComplete();
    
    ST noteTitle, noteContent;
    console.printLine("\n=== Ingresa tu Nota ===");
    cout << "Titulo de la nota: ";
    getline(cin, noteTitle);
    cout << "Contenido: ";
    getline(cin, noteContent);

    Note* idea = new Note(noteTitle, noteContent);

    ST goalTitle, goalUnit;
    I goalTarget, goalProgress;
    console.printLine("\n=== Ingresa tu Meta ===");
    cout << "Titulo de la meta: ";
    getline(cin, goalTitle);
    cout << "Unidad (ej: libros, km, paginas): ";
    getline(cin, goalUnit);
    cout << "Cantidad objetivo: ";
    cin >> goalTarget;
    cout << "Progreso actual: ";
    cin >> goalProgress;
    cin.ignore();


    Goal* meta = new Goal(goalTitle, goalTarget, goalUnit, {31, 12, 2026}, 2);
    meta->addProgress(goalProgress);

    ST habitTitle;
    console.printLine("\n=== Ingresa tu Habito diario ===");
    cout << "Titulo del habito: ";
    getline(cin, habitTitle);

    Habit* leer = new Habit(habitTitle, 2);
    leer->markDoneToday(today);

    ItemList items;
    items.push_back(proyecto);
    items.push_back(idea);
    items.push_back(meta);
    items.push_back(leer);

    console.printLine("\t");
    console.printLine("ORGANIZADOR PERSONAL");
    console.printLine("=== Todos los items ===");
    for (auto i = 0; i < items.size(); i++) {
        console.print(*items[i]);
    }

    console.printLine("");
    console.printLine("Proyecto completo (incluyendo subtareas)? " +
                       ST(proyecto->isComplete() ? "si" : "no"));
    console.printLine("Total de subtareas anidadas: " +
                       to_string(proyecto->countSubtasks()));

    I diaTask, horaTask, diaHabit, horaHabit;
    console.printLine("\n=== Agenda semanal ===");
    cout << "Dia para tu tarea (0=Lunes, 1=Martes, 2=Miercoles, 3=Jueves, 4=Viernes, 5=Sabado, 6=Domingo): ";
    cin >> diaTask;
    cout << "Hora para tu tarea (0=8:00, 1=9:00, 2=10:00 ... 11=19:00): ";
    cin >> horaTask;
    cout << "Dia para tu habito (0=Lunes ... 6=Domingo): ";
    cin >> diaHabit;
    cout << "Hora para tu habito (0=8:00 ... 11=19:00): ";
    cin >> horaHabit;
    cin.ignore();

    Calendar agenda;
    agenda.scheduleItem(static_cast<Day>(diaTask), horaTask, proyecto);
    agenda.scheduleItem(static_cast<Day>(diaHabit), horaHabit, leer);

    console.printLine("");
    console.printLine("=== Agenda semanal ===");
    console.print(agenda.toString());

    MemoryPrinter buffer;
    for (auto i = 0; i < items.size(); i++) {
        buffer.print(*items[i]);
    }
    console.printLine("");
    console.printLine("=== Capturado en memoria (MemoryPrinter) ===");
    //console.print(buffer.getContent());

    FilePrinter archivo("lifeos_log.txt");
    for (auto i = 0; i < items.size(); i++) {
        archivo.print(*items[i]);
    }
    console.printLine("");
    console.printLine("Tambien se guardo una copia en lifeos_log.txt");

    ItemList porBurbuja = items; 
    BurbujaClasico(&porBurbuja[0], porBurbuja.size(), MenorPrioridad);

    ItemList porQuick = items;
    QuickSort(&porQuick[0], 0, porQuick.size() - 1, MenorPrioridad);

    ItemList porMerge = items;
    MergeSort(&porMerge[0], 0, porMerge.size() - 1, MenorPrioridad);

    console.printLine("");
    console.printLine("=== Orden por prioridad ===");
    //console.printLine("Burbuja:");
    //for (auto i = 0; i < porBurbuja.size(); i++) {
    //    console.printLine("  " + porBurbuja[i]->getTitle());
    //}
    console.printLine("QuickSort:");
    for (auto i = 0; i < porQuick.size(); i++) {
        console.printLine("  " + porQuick[i]->getTitle());
    }
    //console.printLine("Merge:");
    //for (auto i = 0; i < porMerge.size(); i++) {
    //    console.printLine("  " + porMerge[i]->getTitle());
    //}

    freeAll(items);

    return 0;
}
