#include <Wt/Dbo/Dbo.h>
#include <Wt/Dbo/Types.h>
#include <Wt/Dbo/WtSqlTraits.h>
#include <Wt/WDate.h>
#include <iostream>

namespace dbo = Wt::Dbo;

class Publisher;

class Book;

class Store;

class Inventory;

class Sale;

class Publisher {
public:
    dbo::ptr<Publisher> self;
    dbo::collection<dbo::ptr<Book>> books;
    std::string name;

    template<class Action>
    void persist(Action& a) {
        dbo::field(a, name, "name");
        dbo::hasMany(a, books, dbo::ManyToOne, "publisher");
    }
};

class Book {
public:
    dbo::ptr<Book> self;
    dbo::ptr<Publisher> publisher;
    std::string title;

    template<class Action>
    void persist(Action& a) {
        dbo::field(a, title, "title");
        dbo::belongsTo(a, publisher, "publisher");
    }
};

class Store {
public:
    dbo::ptr<Store> self;
    dbo::collection<dbo::ptr<Inventory>> inventories;
    dbo::collection<dbo::ptr<Sale>> sales;
    std::string name;

    template<class Action>
    void persist(Action& a) {
        dbo::field(a, name, "name");
        dbo::hasMany(a, inventories, dbo::ManyToOne, "store");
        dbo::hasMany(a, sales, dbo::ManyToOne, "store");
    }
};

class Inventory {
public:
    dbo::ptr<Inventory> self;
    dbo::ptr<Book> book;
    dbo::ptr<Store> store;
    int quantity;

    template<class Action>
    void persist(Action& a) {
        dbo::belongsTo(a, book, "book");
        dbo::belongsTo(a, store, "store");
        dbo::field(a, quantity, "quantity");
    }
};

class Sale {
public:
    dbo::ptr<Sale> self;
    dbo::ptr<Book> book;
    dbo::ptr<Store> store;
    Wt::WDate sale_date;

    template<class Action>
    void persist(Action& a) {
        dbo::belongsTo(a, book, "book");
        dbo::belongsTo(a, store, "store");
        dbo::field(a, sale_date, "sale_date");
    }
};

int main() {
    dbo::Session session;
    session.setConnection("postgresql://username:password@localhost/database");

    dbo::Transaction transaction(session);
    session.createTables();
    transaction.commit();

    dbo::Transaction transaction2(session);

    dbo::ptr<Publisher> publisher = session.add(std::make_unique<Publisher>());
    publisher.modify()->name = "Издатель1";

    dbo::ptr<Book> book = session.add(std::make_unique<Book>());
    book.modify()->title = "Книга1";
    book.modify()->publisher = publisher;

    dbo::ptr<Store> store = session.add(std::make_unique<Store>());
    store.modify()->name = "Магазин1";

    dbo::ptr<Inventory> inventory = session.add(std::make_unique<Inventory>());
    inventory.modify()->book = book;
    inventory.modify()->store = store;
    inventory.modify()->quantity = 10;

    dbo::ptr<Sale> sale = session.add(std::make_unique<Sale>());
    sale.modify()->book = book;
    sale.modify()->store = store;
    sale.modify()->sale_date = Wt::WDate::currentDate();

    transaction2.commit();

    std::string publisherName;
    std::cout << "Введите имя издателя: ";
    std::cin >> publisherName;

    dbo::Transaction transaction3(session);
    dbo::ptr<Publisher> requestedPublisher = session.query<Publisher>().where("name = ?").bind(publisherName).resultValue();
    if (requestedPublisher) {
        std::cout << "Издатель: " << requestedPublisher.get()->name << std::endl;
        std::cout << "Книги издателя:" << std::endl;
        for (dbo::ptr<Book> book : requestedPublisher.get()->books) {
            std::cout << " - " << book.get()->title << std::endl;
        }
    } else {
        std::cout << "Издатель не найден." << std::endl;
    }
    transaction3.commit();

    dbo::Transaction transaction4(session);
    if (requestedPublisher) {
        std::cout << "Магазины, в которых продаются книги издателя:" << std::endl;
        for (dbo::ptr<Book> book : requestedPublisher.get()->books) {
            for (dbo::ptr<Inventory> inventory : book.get()->inventories) {
                std::cout << " - " << inventory.get()->store.get()->name << std::endl;
            }
        }
    }
    transaction4.commit();

    session.flush();

    return 0;
}
