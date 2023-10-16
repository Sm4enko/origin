#include <Wt/Dbo/Dbo.h>
#include <Wt/Dbo/backend/Postgres.h>
template <typename T>
int main()
{
    namespace dbo = Wt::Dbo;

    class Manufacturer;

    class Product {
    public:
        std::string name;
        double price;
        dbo::ptr<Manufacturer> manufacturer;

        template<class Action>
        void persist(Action& a) {
            dbo::field(a, name, "name");
            dbo::field(a, price, "price");
            dbo::belongsTo(a, manufacturer, "manufacturer");
        }
    };

    class Manufacturer {
    public:
        std::string name;
        dbo::collection<dbo::ptr<Product>> products;

        template<class Action>
        void persist(Action& a) {
            dbo::field(a, name, "name");
            dbo::hasMany(a, products, dbo::ManyToOne, "manufacturer");
        }
    };

    class Stock {
    public:
        int quantity;
        dbo::ptr<Product> product;

        template<class Action>
        void persist(Action& a) {
            dbo::field(a, quantity, "quantity");
            dbo::belongsTo(a, product, "product");
        }
    };

    class Sale {
    public:
        std::string date;
        dbo::collection<dbo::ptr<Product>> products;
        dbo::ptr<Store> store;

        template<class Action>
        void persist(Action& a) {
            dbo::field(a, date, "date");
            dbo::hasMany(a, products, dbo::ManyToMany, "sale");
            dbo::belongsTo(a, store, "store");
        }
    };

    class UnsoldProduct {
    public:
        std::string reason;
        dbo::ptr<Product> product;

        template<class Action>
        void persist(Action& a) {
            dbo::field(a, reason, "reason");
            dbo::belongsTo(a, product, "product");
        }
    };

    class Store {
    public:
        std::string name;
        dbo::collection<dbo::ptr<Sale>> sales;

        template<class Action>
        void persist(Action& a) {
            dbo::field(a, name, "name");
            dbo::hasMany(a, sales, dbo::ManyToMany, "store");
        }
    };

    DBO_EXTERN_TEMPLATES(Manufacturer, Product, Stock, Sale, UnsoldProduct, Store);

    int main() {
        dbo::backend::Sqlite3 connection("mydb.sqlite");
        connection.setProperty("show-queries", "true");

        dbo::Session session;
        session.setConnection(connection);
        session.mapClass<Manufacturer>("manufacturer");
        session.mapClass<Product>("product");
        session.mapClass<Stock>("stock");
        session.mapClass<Sale>("sale");
        session.mapClass<UnsoldProduct>("unsoldproduct");
        session.mapClass<Store>("store");

        dbo::Transaction transaction(session);
        session.createTables();
        transaction.commit();

        dbo::Transaction insertTransaction(session);
        dbo::ptr<Manufacturer> samsung = session.add(new Manufacturer());
        samsung.modify()->name = "Samsung";

        dbo::ptr<Product> tv = session.add(new Product());
        tv.modify()->name = "Smart TV";
        tv.modify()->price = 799.99;
        tv.modify()->manufacturer = samsung;

        dbo::ptr<Stock> stock = session.add(new Stock());
        stock.modify()->quantity = 50;
        stock.modify()->product = tv;

        dbo::ptr<Store> store = session.add(new Store());
        store.modify()->name = "Electronics Store";

        dbo::ptr<Sale> sale = session.add(new Sale());
        sale.modify()->date = "2023-10-16";
        sale.modify()->store = store;
        sale.modify()->products.insert(tv);

        dbo::ptr<UnsoldProduct> unsold = session.add(new UnsoldProduct());
        unsold.modify()->reason = "Out of stock";
        unsold.modify()->product = tv;

        insertTransaction.commit();

        dbo::Transaction selectTransaction(session);
        dbo::ptr<Manufacturer> manufacturer = session.query<Manufacturer>().where("name = ?").bind("Samsung").resultValue();
        if (manufacturer) {
            std::cout << "Manufacturer: " << manufacturer.modify()->name << std::endl;
        }

        dbo::ptr<Product> product = session.query<Product>().where("name = ?").bind("Smart TV").resultValue();
        if (product) {
            std::cout << "Product: " << product.modify()->name << ", Price: " << product.modify()->price << std::endl;
        }

        return 0;
    }


	return 0;
}