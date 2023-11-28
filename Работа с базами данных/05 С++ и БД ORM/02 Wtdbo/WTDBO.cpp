#include <iostream>
#include <string>
#include <Wt/Dbo/Dbo.h>
#include <Wt/Dbo/backend/Postgres.h>

class Book;



class Publisher {
public:
	std::string name;
	Wt::Dbo::collection<Wt::Dbo::ptr<Book>> books;
	template <typename Action>
	void persist(Action& a) {
		Wt::Dbo:field(a, name, "name");
		Wt::Dbo::hasMany(a, books, Wt::Dbo::ManyToOne, "publisher");
	}
};

class Stock;

class Book {
     public:
		 std::string title;
		 Wt::Dbo::ptr<Publisher>> publisher;
		 Wt::Dbo::collection<Wt::Dbo::ptr<Stock>> stocks;
		 template <typename Action>
		 void persist(Action& a) {
			 Wt::Dbo:field(a, name, "title");
			 Wt::Dbo::belongsTo(a, publisher, "publisher");
			 Wt::Dbo::hasMany(a, stocks, Wt::Dbo::ManyToOne, "book");
		 }

};

class Shop {
public:
	std::string name;
	Wt::Dbo::collection<Wt::Dbo::ptr<Stock>> stocks;
	template <typename Action>
	void persist(Action& a) {
		Wt::Dbo:field(a, name, "name");
		Wt::Dbo::hasMany(a, stocks, Wt::Dbo::ManyToOne, "shop");
	}
};

class Sale;

class Stock {
public:
	int count = 0;
	Wt::Dbo::ptr<Book> book;
	Wt::Dbo::ptr<Shop> shop;
	Wt::Dbo::collection<Wt::Dbo::ptr<Sale>> sales;
	template <typename Action>
	void persist(Action& a) {
		Wt::Dbo:field(a, name, "title");
		Wt::Dbo::belongsTo(a, book, "book");
		Wt::Dbo::belongsTo(a, shop, "shop");
		Wt::Dbo::hasMany(a, sales, Wt::Dbo::ManyToOne, "stock");
	}

};

class Sale {
public:
	int price = 0, count = 0;
	std::string data_sale;
	Wt::Dbo::ptr<Stock> stock;

	template <typename Action>

	void persist(Action& a) {
		Wt::Dbo:field(a, price, "price");
		Wt::Dbo:field(a, count, "count");
		Wt::Dbo:field(a, data_sale, "data_sale");
		Wt::Dbo::belongsTo(a, stock, "stock");
	}

};


int main()
{
	try {
		std::string connectionString = "host = localhost port = 5432 dbname=lesson03 user=acc45 password = acc45";
		std::unique_ptr<Wt::Dbo::backend::Postgres> conn = std::make_unique<>(connectionString);
		Wt::Dbo::Session session;
		session.setConnection(std::move(conn));
		session.mapClass<Publisher>("publisher");
		session.mapClass<Book>("book");
		session.mapClass<Shop>("shop");
		session.mapClass<Stock>("stock");
		session.mapClass<Sale>("sale");
	

	

	try {
		//session.dropTables();
		session.createTables();
	}
	catch (const std::exception& e) {
		std::cout << "Create error" << e.what() << std::endl;
	}
	Wt::Dbo::Transcaction transaction(session);
	

	auto p1db = session.add<Publisher>(new Publisher{ "Eksmo" }); 

	std::unique_ptr<Book> p1(new Book{ "Bird" });
	auto b1db = session.add<Book>(std::move(b1));

	b1db.modify()->publisher = p1db;

	transaction.commit();

	std::cout << "Enter book name: ";

	std::string str;
	std::getline(std::cin, str);

	Wt::Dbo::Transcaction transaction2(session);

	Wt::Dbo::collection<Wt::Dbo::ptr<Book>> books = session.find<Book>().where"title=?").bind(str);

	for (auto& book : books) {
		std::string publisher = book->publisher->name;
		std::cout << "Publisher is: " << publisher << std::endl;
	}
	transaction2.commit();
	}

	catch (const std::exception& e) {
		std::cout << "Error\n";
	}

}
