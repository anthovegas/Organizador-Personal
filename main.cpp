#include <string>
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

using ItemList = CVector<Item*>; 

void freeAll(ItemList& items) {
    for (int i = 0; i < items.size(); i++) {
        delete items[i];
    }
}

int main() {
    Date today = {27, 6, 2026};

    Task* proyecto = new Task("Proyecto LifeOS", 1);
    proyecto->addSubtask(new Task("Disenar las clases", 2));
    proyecto->addSubtask(new Task("Implementar sorting", 2));
    proyecto->markComplete(); 

    Note* idea = new Note("Idea", "Agregar modo oscuro al imprimir en consola");

    Goal* meta = new Goal("Leer 12 libros", 12, "libros", {31, 12, 2026}, 2);
    meta->addProgress(5);

    Habit* leer = new Habit("Leer 20 minutos", 2);
    leer->markDoneToday(today);

    ItemList items;
    items.push_back(proyecto);
    items.push_back(idea);
    items.push_back(meta);
    items.push_back(leer);

    ConsolePrinter console;

    console.printLine("=== Todos los items (polimorfismo) ===");
    for (int i = 0; i < items.size(); i++) {
        console.print(*items[i]);
    }

    console.printLine("");
    console.printLine("Proyecto completo (incluyendo subtareas)? " +
                       std::string(proyecto->isComplete() ? "si" : "no"));
    console.printLine("Total de subtareas anidadas: " +
                       std::to_string(proyecto->countSubtasks()));

    Calendar agenda;
    agenda.scheduleItem(Day::MONDAY, 0, proyecto);
    agenda.scheduleItem(Day::WEDNESDAY, 3, leer);

    console.printLine("");
    console.printLine("=== Agenda semanal ===");
    console.print(agenda.toString());

    MemoryPrinter buffer;
    for (int i = 0; i < items.size(); i++) {
        buffer.print(*items[i]);
    }
    console.printLine("");
    console.printLine("=== Capturado en memoria (MemoryPrinter) ===");
    console.print(buffer.getContent());

    FilePrinter archivo("lifeos_log.txt");
    for (int i = 0; i < items.size(); i++) {
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
    console.printLine("=== Orden por prioridad (deberia ser igual en los 3) ===");
    console.printLine("Burbuja:");
    for (int i = 0; i < porBurbuja.size(); i++) {
        console.printLine("  " + porBurbuja[i]->getTitle());
    }
    console.printLine("Quick:");
    for (int i = 0; i < porQuick.size(); i++) {
        console.printLine("  " + porQuick[i]->getTitle());
    }
    console.printLine("Merge:");
    for (int i = 0; i < porMerge.size(); i++) {
        console.printLine("  " + porMerge[i]->getTitle());
    }

    freeAll(items);

    return 0;
}
