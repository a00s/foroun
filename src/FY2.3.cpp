//============================================================================
// Name        : 3.cpp
// Author      : Thiago Benazzi Maia
// Version     :
// Copyright   : 
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "mysql_connection.h"
#include <cppconn/driver.h>
#include <cppconn/exception.h>
#include <cppconn/resultset.h>
#include <cppconn/prepared_statement.h>
#include <cppconn/statement.h>

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

//IEnumerator startSimulation ()
//	{
//		int looprint = 0;
//		LabelStatus.text = "Running";
//		if (equation1.text != "") {
//			e = new Expression (equation1.text);
//		}
//		if (equationBond.text != "") {
//			eBond = new Expression (equationBond.text);
//		}
//		// Fazendo backup do array
//		int duration = 1000000000;
//		int duration_count = 0;
//		if (loop == 0) {
//			for (int i = 0; i < objetos; i++) {
//				for (int ii = 0; ii < 2; ii++) {
//					particulaPositionOriginal [i, ii] = particulaPosition [i, ii];
//					particulaVelocidadeOriginal [i, ii] = particulaVelocidade [i, ii];
//				}
//			}
//		}
//		while (!pause) {
//			loop++;
//			duration_count++;
//			computeAccelerations ();
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
//	}

//void computeAccelerations ()
//	{
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
//	}


void load_job(int jobid) {
	printf("Vendo quantidade de modelos: %d\n", jobid);
	try {
		sql::Driver *driver;
		sql::Connection *con;
		sql::PreparedStatement *pstmt;
		sql::ResultSet *res;
		driver = get_driver_instance();
		con = driver->connect("tcp://127.0.0.1:3306", "fyequation", "testando");
		con->setSchema("fyequation");
		pstmt = con->prepareStatement("SELECT particle_id, particle_type FROM job_particles WHERE job_id="+jobid);
		res = pstmt->executeQuery();
		while (res->next()) {
			printf("Propriedade %d\n",res->getInt(1));
//			resultado_local = load_protein_position(PDBID, res->getString(1), 1);
//			if (calculated_pdb_min == 0) {
//				calculated_pdb_min = resultado_local;
//				calculated_pdb_max = resultado_local;
//			} else {
//				if (resultado_local < calculated_pdb_min) {
//					calculated_pdb_min = resultado_local;
//				}
//				if (resultado_local > calculated_pdb_max) {
//					calculated_pdb_max = resultado_local;
//				}
//			}
		}
		delete res;
		delete pstmt;
		delete con;
//		printf("MINMAX %f %f\n", calculated_pdb_min, calculated_pdb_max);
	} catch (sql::SQLException &e) {
		printf("%d\n", e.getErrorCode());
	}
}

int main() {
	cout << "Carregando job" << endl;
	load_job(1);
	return 0;
}
