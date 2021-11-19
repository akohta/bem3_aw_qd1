/*
 * bem3_aw_qd1.h
 *
 *  Created on: Nov 15, 2021
 *      Author: ohta
 */

#ifndef BEM3_AW_QD1_H_
#define BEM3_AW_QD1_H_

#include "d3qd1_const.h"
#include "d3qd1_elem.h"

// -- bem3_aw_qd1.c --
void read_aqd1(int argc,char **argv,AQD1 *qd); // read datafile
void print_aqd1(AQD1 *qd);                     // print data
void initialize_aqd1(AQD1 *qd);                // memory allocation and initialize coefficients
void finalize_aqd1(AQD1 *qd);                  // memory free
int domain_id_aqd1(double *rt,AQD1 *qd);       // return domain id of point rt. return the main domain id if on boundary.
int domain_id_l_aqd1(double *rt,AQD1 *qd);     // return domain number l.
void dat_write_aqd1(char *fname,AQD1 *qd);     // write datafile
void dat_read_aqd1(char *fname,AQD1 *qd);      // read datafile 


// -- bem3_aw_qd1_solve_bieq.c --
void solve_bieq_aqd1(AQD1 *qd);                // solve boundary integral equations


// -- bem3_aw_qd1_force.c --
void force_FN(double *F,double *N,double *rc,int type,AQD1 *ad);
void surface_area(double *S,int did,int type,AQD1 *ad);


// -- bem3_aw_qd1_field.c --
int phi_s_aqd1(double complex *phi,double *rt,int type,AQD1 *ad);
int phi_t_aqd1(double complex *phi,double *rt,int type,AQD1 *ad);
int phi_i_aqd1(double complex *phi,double *rt,int type,AQD1 *ad);
int p_s_aqd1(double complex *p,double *rt,int type,AQD1 *ad);
int p_t_aqd1(double complex *p,double *rt,int type,AQD1 *ad);
int p_i_aqd1(double complex *p,double *rt,int type,AQD1 *ad);
int pv_s_aqd1(double complex *p,double complex *pv,double *rt,int type,AQD1 *ad);
int pv_t_aqd1(double complex *p,double complex *pv,double *rt,int type,AQD1 *ad);
int pv_i_aqd1(double complex *p,double complex *pv,double *rt,int type,AQD1 *ad);

void phi_s_bd_aqd1(double complex *phi,int did,int t,double zeta_t,double eta_t,int type,AQD1 *ad);
void phi_t_bd_aqd1(double complex *phi,int did,int t,double zeta_t,double eta_t,int type,AQD1 *ad);
void phi_i_bd_aqd1(double complex *phi,int did,int t,double zeta_t,double eta_t,int type,AQD1 *ad);

void pv_s_bd_aqd1(double complex *p,double complex *pv,int did,int t,double zeta_t,double eta_t,int type,AQD1 *ad);
void pv_t_bd_aqd1(double complex *p,double complex *pv,int did,int t,double zeta_t,double eta_t,int type,AQD1 *ad);
void pv_i_bd_aqd1(double complex *p,double complex *pv,int did,int t,double zeta_t,double eta_t,int type,AQD1 *ad);

#endif
