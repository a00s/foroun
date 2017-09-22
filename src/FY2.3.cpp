//============================================================================
// Author      : Thiago Benazzi Maia
// Version     :
// Copyright   : 
// TODO: Alterar array the posicao para numero, criar array the velocidade e aceleracao
//============================================================================

#include <iostream>
#include "mysql_connection.h"
#include <cppconn/driver.h>
#include <cppconn/exception.h>
#include <cppconn/resultset.h>
#include <cppconn/prepared_statement.h>
#include <cppconn/statement.h>
#include <map>
#include <vector>
#include <math.h>

using namespace std;

//public double Evaluate (int i, int ii, double distance, double bondDistance)
//	{
//		try {
//			if (bondDistance == 0) {
//				e.Parameters ["m1"] = particulaMassa [i];
//				e.Parameters ["m2"] = particulaMassa [ii];
//				e.Parameters ["r1"] = particulaRaio [i];
//				e.Parameters ["r2"] = particulaRaio [ii];
//				e.Parameters ["d"] = distance;
//				return double.Parse (e.Evaluate ().ToString ());
//			} else if (bondDistance > 0) {
//				eBond.Parameters ["m1"] = particulaMassa [i];
//				eBond.Parameters ["m2"] = particulaMassa [ii];
//				eBond.Parameters ["d"] = distance;
//				eBond.Parameters ["b"] = bondDistance;
//				return double.Parse (eBond.Evaluate ().ToString ());
//			} else {
//				return 0.0;
//			}
//
//		} catch (Exception ex) {
//			pause = true;
//			LabelStatus.text = "Equation error";
//			print ("Equacao com erro:" + ex.Message);
//			return 0;
//		}
//	}

void computeAccelerations() {
//		particulaAceleracao = new double[objetosmax, 3];
//		double distance;
//		double force;
//		for (int i = 0; i < objetos; i++) {
//			for (int ii = 0; ii < objetos; ii++) {
//				if (i == ii || particulaMorta [i]) {
//					continue;
//				}
//				distance = show_distance (i, ii);
//				if (bondEquation1 [i, ii] == 0 && equation1.text != "") {
//					force = Evaluate (i, ii, distance, 0);
//					particulaAceleracao [i, 0] += (particulaPosition [i, 0] - particulaPosition [ii, 0]) * force / distance;
//					particulaAceleracao [i, 1] += (particulaPosition [i, 1] - particulaPosition [ii, 1]) * force / distance;
//					particulaAceleracao [i, 2] += (particulaPosition [i, 2] - particulaPosition [ii, 2]) * force / distance;
//				} else if (bondEquation1 [i, ii] > 0) {
//					if ((i == 1 && ii == 2) || (i == 2 && ii == 1)) {
//						print ("Nao 2");
//					}
//					force = Evaluate (i, ii, distance, bondEquation1 [i, ii]);
//					particulaAceleracao [i, 0] += (particulaPosition [i, 0] - particulaPosition [ii, 0]) * force / distance;
//					particulaAceleracao [i, 1] += (particulaPosition [i, 1] - particulaPosition [ii, 1]) * force / distance;
//					particulaAceleracao [i, 2] += (particulaPosition [i, 2] - particulaPosition [ii, 2]) * force / distance;
//				}
//			}
//		}
}

void startSimulation(string equation, int combination[], string particulaType[], string particulaPosition[][3]) {
	cout << "startSimulation:" << equation << "/" << combination[0] << "/" << combination[1] << "/" << combination[2] << "\n";
//		int looprint = 0;
//		while (!pause) {
//			loop++;
//			duration_count++;
	computeAccelerations(&particulaPosition);
//			for (int i = 0; i < objetos; i++) {
//				particulaPosition [i, 0] += particulaVelocidade [i, 0] * deltaT + 0.5 * particulaAceleracao [i, 0] * deltaT * deltaT;
//				particulaPosition [i, 1] += particulaVelocidade [i, 1] * deltaT + 0.5 * particulaAceleracao [i, 1] * deltaT * deltaT;
//				particulaPosition [i, 2] += particulaVelocidade [i, 2] * deltaT + 0.5 * particulaAceleracao [i, 2] * deltaT * deltaT;
//
//				particulaVelocidade [i, 0] += 0.5 * particulaAceleracao [i, 0] * deltaT;
//				particulaVelocidade [i, 1] += 0.5 * particulaAceleracao [i, 1] * deltaT;
//				particulaVelocidade [i, 2] += 0.5 * particulaAceleracao [i, 2] * deltaT;
//			}
//			computeAccelerations ();
//			for (int i = 0; i < objetos; i++) {
//				particulaVelocidade [i, 0] += 0.5 * particulaAceleracao [i, 0] * deltaT;
//				particulaVelocidade [i, 1] += 0.5 * particulaAceleracao [i, 1] * deltaT;
//				particulaVelocidade [i, 2] += 0.5 * particulaAceleracao [i, 2] * deltaT;
//			}
//			looprint++;
//			if (looprint == velocidadeSimulacao) {
//				looprint = 0;
//				double sum_velocities = 0.0;
//				for (int i = 0; i < objetos; i++) {
//					if (particulaMorta [i]) {
//						continue;
//					}
//					mo [i].transform.position = new Vector3 ((float)(particulaPosition [i, 0] / escala), (float)(particulaPosition [i, 1] / escala), (float)(particulaPosition [i, 2] / escala));
//					// Alterando posicao dos bonds
//					drawBonds ();
//					if (showCoordenates == true && i == properties_show_index) {
//						show_properties_set (i);
//					}
//					sum_velocities += particulaVelocidade [i, 0] + particulaVelocidade [i, 1] + particulaVelocidade [i, 2];
//					if (energy_minimization == true) {
//						particulaVelocidade [i, 0] = 0.0;
//						particulaVelocidade [i, 1] = 0.0;
//						particulaVelocidade [i, 2] = 0.0;
//
//					}
//				}
//				LabelTotalSpeed.text = "Total velocity: " + sum_velocities.ToString ();
//				if (tipoTempo == "s") {
//					timeSimulation.text = "Time(s): " + loop + " = " + (loop / 86400) * deltaT + " days";
//				} else {
//					timeSimulation.text = "Time(s): " + loop * deltaT;
//				}
//				yield return null;
//			}
//			if (collision) {
//				for (int i = 0; i < objetos; i++) {
//					if (particulaMorta [i]) {
//						continue;
//					}
//					for (int ii = i + 1; ii < objetos; ii++) {
//						if (i == ii || particulaMorta [i]) {
//							continue;
//						}
//						if (show_distance (i, ii) < (particulaRaio [i] + particulaRaio [ii])) {
//							for (int iii = 0; iii < objetos; iii++) {
//								if (particulaMorta [iii]) {
//									continue;
//								}
//								mo [iii].transform.position = new Vector3 ((float)(particulaPosition [iii, 0] / escala), (float)(particulaPosition [iii, 1] / escala), (float)(particulaPosition [iii, 2] / escala));
//							}
//							GameObject.Destroy (mo [i]);
//							particulaMorta [i] = true;
//
//							GameObject.Destroy (mo [ii]);
//							particulaMorta [ii] = true;
//							pause = true;
//							LabelStatus.text = "Stopped on collision";
//							if (tipoTempo == "s") {
//								timeSimulation.text = "Time(s): " + loop + " = " + (loop / 86400) * deltaT + " days";
//							} else {
//								timeSimulation.text = "Time(s): " + loop * deltaT;
//							}
//						}
//					}
//				}
//			}
//			if (duration_count == duration) {
//				pause = true;
//				LabelStatus.text = "Stopped on limit time";
//			}
//		}
//		yield return null;
}



void load_job(int jobid) {
	printf("Vendo quantidade de modelos B: %d\n", jobid);
	try {
		sql::Driver *driver;
		sql::Connection *con;
		sql::PreparedStatement *pstmt;
		sql::ResultSet *res;
		driver = get_driver_instance();
		con = driver->connect("tcp://127.0.0.1:3306", "fyequation", "testando");
		con->setSchema("fyequation");
		pstmt = con->prepareStatement("SELECT particle_id, particle_type, x, y, z FROM job_particles WHERE job_id = ?");
		pstmt->setInt(1, jobid);
		res = pstmt->executeQuery();

		string particulaPosition[res->rowsCount()][3];
		string particulaType[res->rowsCount()];
		int count = 0;
		while (res->next()) {
			particulaType[count] = res->getString("particle_type");
			particulaPosition[count][0] = res->getString("x");
			particulaPosition[count][1] = res->getString("y");
			particulaPosition[count][2] = res->getString("z");
		}
		delete res;
		delete pstmt;

		// Coletando constantes e atomic properties
		pstmt = con->prepareStatement("SELECT CONCAT('P:1:',id), 0 FROM atoms_properties UNION ALL SELECT CONCAT('P:2:',id), 0 FROM atoms_properties UNION ALL SELECT CONCAT('C:',id), value FROM constants");
		res = pstmt->executeQuery();
		string constants[res->rowsCount()][2];
		string propriedades[res->rowsCount() + 1] = { };
		// The first is for the distance
		int contador_propriedades = 0;
		map<int, map<string, string>> list_properties;
		list_properties[0]["name"] = "D";
		list_properties[0]["value"] = "0";
		while (res->next()) {
			contador_propriedades++;
			list_properties[contador_propriedades]["name"] = res->getString(1).c_str();
			list_properties[contador_propriedades]["value"] = res->getString(2).c_str();
		}

		delete res;
		delete pstmt;

		// Getting the equations
		pstmt = con->prepareStatement("SELECT equation FROM equations WHERE id=?");
		pstmt->setInt(1, 1);
		res = pstmt->executeQuery();
		string equation = "";
		while (res->next()) {
			equation = res->getString(1).c_str();
		}

		delete res;
		delete pstmt;

		printf("Equation %s\n", equation.c_str());
		int contX = 0;
		for (unsigned int i = 0; i < equation.length(); i++) {
			if (equation[i] == 'X') {
				contX++;
			}
		}
		cout << contX << "\n";

		int combination[contX] = { 0 };
		cout << pow(contador_propriedades, contX) << "\n";
		int count_stop = 0;
		cout << "Realizar combinacao de " << contador_propriedades << "\n";
		for (int ic = 0; ic < pow(contador_propriedades + 1, contX); ic++) {
			bool last_increase = true;
			if (ic > 0) {
				for (int ii = contX - 1; ii >= 0 && last_increase == true; ii--) {
					if (combination[ii] == contador_propriedades) {
						combination[ii] = 0;
						last_increase = true;
					} else {
						combination[ii] = combination[ii] + 1;
						last_increase = false;
					}
				}
			}
			bool have_distance = false;
			bool have_p1 = false;
			bool have_p2 = false;
			for (int ii = 0; ii < contX; ii++) {
				if (list_properties[combination[ii]]["name"] == "D") {
					have_distance = true;
				} else if (list_properties[combination[ii]]["name"].substr(0, 3) == "P:1") {
					have_p1 = true;
				} else if (list_properties[combination[ii]]["name"].substr(0, 3) == "P:2") {
					have_p2 = true;
				}
			}
			if (have_distance == true && have_p1 == true && have_p2 == true) {
				count_stop++;
				for (int ii = 0; ii < contX; ii++) {
					if (list_properties[combination[ii]]["value"] != "0") {
						cout << "[V" << list_properties[combination[ii]]["value"] << "]";
					} else {
						cout << "[" << list_properties[combination[ii]]["name"] << "]";
					}
				}
				cout << "\n";
				cout << "before:" << equation << "/" << combination[0] << "/" << combination[1] << "\n";
				startSimulation(equation, combination, particulaType, particulaPosition);
				if (count_stop >= 1) break;
			}
		}
		cout << "Final\n";
//		vector<int> index, imits;
//		std::vector<function> functions;
//		//omitting initializations
//		while (1){
//			functions[0]();
//			index[0]++;
//			for (int a=0;a<index.size()-1;a++){
//				if (index[a]==limits[a]){
//					index[a]=0;
//					functions[a+1]();
//					index[a+1]++;
//				}else
//					break;
//			}
//			if (index.back())
//				break;
//		}

// coletando quantidade de atomos diferentes
//		pstmt =
//				con->prepareStatement(
//						"SELECT COUNT(DISTINCT(particle_type)) FROM job_particles WHERE job_id=?");
//		pstmt->setInt(1, jobid);
//		res = pstmt->executeQuery();
//		map<string, map<int, string>> atom_properties;

// Coletando informacoes sobre atomos
//		pstmt = con->prepareStatement(
//				"SELECT id, atom, description, value FROM atoms");
//		pstmt->setInt(1, jobid);
//		res = pstmt->executeQuery();
//
//		delete res;
//		delete pstmt;

//		string particulaAceleracao[res->rowsCount()][3];
//		string particulaPosition[res->rowsCount()][3];
//		string particulaType[res->rowsCount()];
//		int count = 0;
//		while (res->next()) {
//			printf("Propriedade %d\n", res->getInt(1));
//			particulaType[count] = res->getString("particle_type");
//
//			particulaAceleracao[count][0] = "0";
//			particulaAceleracao[count][1] = "0";
//			particulaAceleracao[count][2] = "0";
//
//			particulaPosition[count][0] = res->getString("x");
//			particulaPosition[count][1] = res->getString("y");
//			particulaPosition[count][2] = res->getString("z");
//		}
//		delete res;
//		delete pstmt;
//
//		id | atom | description | value | unit

		delete con;
	} catch (sql::SQLException &e) {
		printf("%d\n", e.getErrorCode());
	}
}

int main() {
	cout << "Carregando job" << endl;
	try {
		load_job(1);
	} catch (...) {
		printf("Erro\n");
		//		printf("%s",e);
	}

	return 0;
}
