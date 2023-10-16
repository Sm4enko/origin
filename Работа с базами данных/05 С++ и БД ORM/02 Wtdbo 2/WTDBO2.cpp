#include <iostream>
#include <pqxx/pqxx>
#include <Wt/Dbo/Dbo>
#include <Wt/Dbo/impl>
#include <Wt/Dbo/Sqlite3>
#include <Wt/WApplication>
#include <Wt/WEnvironment>

int main() {
    namespace dbo = Wt::Dbo;

    class Manufacturer;
    class Product;

    typedef Wt::Dbo::collection< dbo::ptr<Product> > Products;
    typedef Wt::Dbo::collection< dbo::ptr<Manufacturer> > Manufacturers;

    class Manufacturer {
    public:
        std::string name;
        Products products;

        template<class Action>
        void persist(Action& a) {
            Wt::Dbo::field(a, name, "name");
            Wt::Dbo::hasMany(a, products, Wt::Dbo::ManyToMany, "manufacturer");
        }
    };

    class Product {
    public:
        std::string name;
        double price;
        Manufacturers manufacturers;

        template<class Action>
        void persist(Action& a) {
            Wt::Dbo::field(a, name, "name");
            Wt::Dbo::field(a, price, "price");
            Wt::Dbo::manyToMany(a, "manufacturer", manufacturers, Wt::Dbo::ManyToOne);
        }
    };

    Wt::WApplication* createApplication(const Wt::WEnvironment & env) {
        Wt::Dbo::backend::Postgres conn("dbname=mydb user=myuser password=mypassword host=127.0.0.1 port=5432");
        Wt::Dbo::Session session;
        session.setConnection(conn);

        session.mapClass<Manufacturer>("manufacturer");
        session.mapClass<Product>("product");

        Wt::Dbo::Transaction transaction(session);
        session.createTables();
        transaction.commit();

        std::string manufacturerName;
        std::cout << "Enter the name of the manufacturer: ";
        std::cin >> manufacturerName;

        dbo::Transaction selectTransaction(session);
        dbo::ptr<Manufacturer> manufacturer = session.query<Manufacturer>().where("name = ?").bind(manufacturerName).resultValue();
        if (manufacturer) {
            std::cout << "Manufacturer: " << manufacturer.modify()->name << std::endl;
        }
        else {
            std::cout << "Manufacturer not found." << std::endl;
        }

        return new Wt::WApplication(env);
    }


