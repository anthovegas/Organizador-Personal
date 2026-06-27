#include <string>
#include "item.h"
#include "task.h"
#include "note.h"
#include "goal.h"
#include "habit.h"
#include "date.h"
#include  "calendar.h"
#include "printer.h"
#include "console_printer.h"
#include "file_printer.h"
#include "memory_printer.h"
#include "cvector.h"

using ItemList = CVector<Item*>;

void freeAll(ItemList& items) {
    for (auto i = 0; i < items.size(); i++) {
        delete items[i];
    }
}

int main() {
    Date today = {27, 6, 2026};

    Task* proyecto = new Task("Proyecto LifeOs", 1);
    proyecto->addSubtask(new Task("Diseñar las clases", 2));
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

    console.printLine("=== Todos los items(polimorfismo) ===");
    for (auto i = 0; i < items.size(); i++) {
        console.print(*items[i]);
    }

    console.printLine("");
    console.printLine("Proyecto completo (incluyendo subtareas)? " +
                        S(proyecto->isComplete() ? "si" : "no"));
    console.printLine("Total de subtareas anidadas: " +
                        to_string(proyecto->countSubtasks()));

    Calendar agenda;
    agenda.scheludeItem(Day::MONDAY, 0, proyecto);
    agenda.scheludeItem(Day::WEDNESDAY, 3, leer);

    console.printLine("");
    console.printLine("=== Agenda semanal ===");
    console.print(agenda.toString());

    MemoryPrinter buffer;
    for (auto i = 0; i < items.size(); i++) {
        buffer.print(*items[i]);
    }

    console.printLine("");
    console.printLine("=== Capturado en memoria (MemoryPrinter) ===");
    console.print(buffer.getContent());

    FilePrinter archivo("lifeos_log.txt");
    for (auto i = 0; i < items.size(); i++) {
        archivo.print(*items[i])
    }

    console.printLine("");
    console.printLine("Tambien se guardo una copia en lifeos_log.txt");

    auto byPriority = [](Item* a, Item* b) {
        return a->getPriority() < b->getPriority();
    };

    ItemList porBurbuja = items;
    bubbleSort(porBurbuja, )
}