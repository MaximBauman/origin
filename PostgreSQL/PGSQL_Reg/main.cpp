#include <pqxx/pqxx>
#include <iostream>

class DBManager {
public:
	pqxx::connection connect;
	DBManager() : connect(
			"host=localhost "
			"port=5432 " 
			"dbname=postgres " 
			"user=postgres " 
			"password=") /*input password*/
	{
		std::cout << "Connection OK\n";
	}

	void create_tables() {
		try {
			pqxx::work tx(connect);
			tx.exec("CREATE TABLE IF NOT EXISTS users("
				"id SERIAL PRIMARY KEY,"
				"name VARCHAR(60) NOT NULL,"
				"surname VARCHAR(60) NOT NULL"
				");");

			tx.exec("CREATE TABLE IF NOT EXISTS users_mail("
				"id SERIAL PRIMARY KEY,"
				"user_id INT NOT NULL REFERENCES users(id),"
				"mail_address VARCHAR(80) NOT NULL"
				");");

			tx.exec("CREATE TABLE IF NOT EXISTS users_phones("
				"id SERIAL PRIMARY KEY,"
				"user_id INT NOT NULL REFERENCES users(id),"
				"phone_type VARCHAR(60),"
				"phone_number VARCHAR(30)"
				");");

			tx.commit();
			std::cout << "Table create successfully!" << std::endl;
		}
		catch (std::exception& e) {
			std::cout << "Something wrong!" << e.what() << std::endl;
		}
	};

	void add_new_client(std::string name, std::string surname, std::string mail) {
		try {
			pqxx::work tx(connect); 
			std::string esc_name = tx.quote(name);
			std::string esc_surname = tx.quote(surname);
			std::string esc_mail = tx.quote(mail);

			tx.exec("INSERT INTO users(name, surname) "
				"VALUES (" + esc_name + ", " + esc_surname + ")");
			for (auto [id] : tx.query<int>(
				"SELECT id FROM users WHERE name =" + esc_name + " AND surname=" + esc_surname + ";"
			)) {
				tx.exec("INSERT INTO users_mail(user_id, mail_address) "
					"VALUES (" + std::to_string(id) + ", " + esc_mail + ")");
			}
			tx.commit();
			std::cout << "New user add successfully!" << std::endl;
		}
		catch (std::exception& e) {
			std::cout << "Can't add new user :(" << e.what() << std::endl;
		}
	}

	void add_phone_number(std::string phone_number, std::string phone_type, std::string user_name, std::string user_surname) {
		int user_id;
		std::setlocale(LC_ALL, nullptr);
		try{
			pqxx::work tx(connect);
			std::string esc_phone_type = tx.quote(phone_type);
			std::string esc_phone_number = tx.quote(phone_number);
			std::string esc_user_name = tx.quote(user_name);
			std::string esc_user_surname = tx.quote(user_surname);
			for (auto [id] : tx.query<int>(
				"SELECT id FROM users WHERE name=" + esc_user_name + " AND surname=" + esc_user_surname + ";"
			)) {
				tx.exec("INSERT INTO users_phones(user_id, phone_type, phone_number) "
					"VALUES (" + std::to_string(id) + ", " + esc_phone_type + ", " + esc_phone_number + ");");
				tx.commit();
				std::cout << "Phone add successfully!" << std::endl;
			}
		}
		catch (std::exception& e) {
			std::cout << "Can't add phone number for this user :(" << e.what() << std::endl;
		}
	}

	void change_info(std::string new_value, std::string param_to_change, std::string where, std::string what_change, std::string user_name, std::string user_surname) {
		try {
			pqxx::work tx(connect);
			std::string esc_value = tx.quote(new_value);
			std::string esc_what_change = tx.quote(what_change);
			std::string esc_user_name = tx.quote(user_name);
			std::string esc_user_surname = tx.quote(user_surname);

			for (auto [id] : tx.query<int>(
				"SELECT id FROM users WHERE name=" + esc_user_name + " AND surname=" + esc_user_surname + ";"
			))
			{
			tx.exec(
				"UPDATE " + where + " SET " + param_to_change + "=" + esc_value + " WHERE " + param_to_change + "=" + esc_what_change + " AND user_id=" + std::to_string(id)
			);
		}
		tx.commit();
		}
		catch (std::exception& e) {
			std::cout << "Can't change info!" << e.what() << std::endl;
		}

	}

	void remove_phone(std::string user_name, std::string user_surname, std::string phone_num) {
		try {
			pqxx::work tx(connect);
			std::string esc_phone_num = tx.quote(phone_num);
			std::string esc_user_name = tx.quote(user_name);
			std::string esc_user_surname = tx.quote(user_surname);



			for (auto [id] : tx.query<int>(
				"SELECT id FROM users WHERE name=" + esc_user_name + " AND surname=" + esc_user_surname + ";"
			)) {
				tx.exec("DELETE FROM users_phones "
				"WHERE user_id=" + std::to_string(id) + " AND phone_number=" + esc_phone_num + ";"
				);
				tx.commit();
				std::cout << "Phone removed successfully!" << std::endl;
			}
		}
		catch (std::exception& e) {
			std::cout << "Can't remove phone!" << e.what() << std::endl;
		}
	}

	void remove_user(std::string user_name, std::string user_surname) {
		try {
			pqxx::work tx(connect);
			std::string esc_user_name = tx.quote(user_name);
			std::string esc_user_surname = tx.quote(user_surname);


			for (auto [id] : tx.query<int>(
				"SELECT id FROM users WHERE name =" + esc_user_name + " AND surname=" + esc_user_surname + ";"
			)) {
				tx.exec("DELETE FROM users_mail WHERE user_id=" + std::to_string(id) + ";");
				tx.exec("DELETE FROM users_phones WHERE user_id=" + std::to_string(id) + ";");
				tx.exec("DELETE FROM users WHERE id=" + std::to_string(id) + ";");
				tx.commit();
				std::cout << "User removed successfully!" << std::endl;
			}
		}
		catch (std::exception& e) {
			std::cout << "Can't remove user :(" << e.what() << std::endl;
		}
	}

	void search_user(std::string user_name, std::string user_surname, std::string user_phone, std::string user_mail) {
		try {
			pqxx::work tx(connect);
			std::string query = "SELECT * FROM users "
				"LEFT JOIN users_mail ON users.id = users_mail.user_id "
				"LEFT JOIN users_phones ON users.id = users_phones.user_id WHERE 1=1";
			if (!user_name.empty()) {
				query += " AND users.name=" + tx.quote(user_name);
			}
			if (!user_surname.empty()) {
				query += " AND users.surname=" + tx.quote(user_surname);
			}
			if (!user_phone.empty()) {
				query += " AND users_phones.phone_number=" + tx.quote(user_phone);
			}
			if (!user_mail.empty()) {
				query += " AND users_mail.mail_adress=" + tx.quote(user_mail);
			}

			pqxx::result result = tx.exec(query);
			for (auto value : result) {
				std::cout << "Name: " << value["name"] << " Surname: " << value["surname"] << std::endl; 
				std::cout << " Phone: " << value["phone_number"] << " Mail: " << value["mail_address"] << std::endl;
			}
		}
		catch (std::exception& e) {
			std::cout << "Can't parse user :(" << e.what() << std::endl;
		}
	}
};

int main() {
		try
		{
			DBManager db_worker;
			db_worker.create_tables();
			db_worker.add_new_client("Max", "Bauman", "m.baumax.x@gmail.com");
			db_worker.add_new_client("Morgan", "Freeman", "morganfreeman@gmail.com");
			db_worker.add_new_client("Ivan", "Ivanov", "iavn@gmail.com");
			db_worker.add_new_client("Timur", "Filippov", "tsf@gmail.com");
			db_worker.add_phone_number("+79991234567", "mobile", "Max", "Bauman");
			db_worker.add_phone_number("+74951234567", "home", "Max", "Bauman");
			db_worker.add_phone_number("+79997654321", "mobile", "Ivan", "Ivanov");
			db_worker.add_phone_number("+19321341283", "mobile", "Morgan", "Freeman");
			db_worker.change_info("home", "phone_type", "users_phones", "mobile", "Morgan", "Freeman");
			db_worker.remove_phone("Max", "Bauman", "+74951234567");
			db_worker.remove_user("Ivan", "Ivanov");
			db_worker.search_user("Morgan", "", "", "");
			db_worker.search_user("", "", "+79991234567", "");

		}
		catch (pqxx::sql_error e) {
			std::cout << e.what() << std::endl;
		}
		catch (std::exception& e)
		{
			std::cout << e.what() << std::endl;
		}
		return 0;
}