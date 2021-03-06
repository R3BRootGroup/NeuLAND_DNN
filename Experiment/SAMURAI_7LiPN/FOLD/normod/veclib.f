      FUNCTION FAC(N) 
C
C      FACTORIAL N!
C
      FAC=1.
      IF (N-1) 30,30,10 
10    DO 20 I=1,N 
20    FAC=FLOAT(I)*FAC
30    RETURN
      END 
C
	FUNCTION GAM(N)
C
C	GAMMA(N) = (N-1)!
C
	M=N-1
	GAM=FAC(M)
	RETURN
	END
C
      FUNCTION GAMH(N)
C
C      GAMMAFUNCTION OF (N+1/2) 
C
      GAMH=SQRT(3.1415926)
      IF (N-1) 30,10,10 
10    DO 20 I=1,N 
20    GAMH=(FLOAT(I)-0.5)*GAMH
30    RETURN
      END 
      FUNCTION PAR(N)
C
C     SUBROUTINE TO CALCULATE (-1) TO THE NTH POWER
C
      PAR=1.
      IF((N/2)*2..NE.N) PAR=-1.
      RETURN
      END
C
      FUNCTION TR(A1,A2,A3) 
C
C	TRIANGLE RELATION: TR=1. IF A1,A2,A3 CAN FORM A TRIANGLE
C	ELSE TR=-1.
C
      IF(A1+A2-A3.LT.0..OR.A1-A2+A3.LT.0..OR.-A1+A2+A3.LT.0.) GOTO 2
      TR=1. 
      RETURN
2     TR=-1.
      RETURN
      END 
C 
      FUNCTION BINOM(A,B) 
C
C	BINOMIAL COEFFICIENT     A!/[(B!)((A-B)!)]
C
      IF(B.EQ.0.) GOTO 12 
      IF(A.EQ.B) GOTO 12
      IF(A-B.GT.B) GOTO 9 
      M=A-B 
      GOTO 11 
9     M=B 
11    BINOM=1.
      X=A-FLOAT(M)
      DO 10 I=1,M 
      AI=I
10    BINOM=BINOM*(X+AI)/AI 
      RETURN
12    BINOM=1.
      RETURN
      END 
C
      FUNCTION THREEJ(A1,A2,A3,B1,B2,B3)
C
C	THREE-J SYMBOL
C
      IF(TR(A1,A2,A3).LT.0.) GOTO 8 
      IF(B1+B2+B3.NE.0.) GOTO 8 
      NPAR=IFIX(2.*(A1+A2+A3))
      IF(PAR(NPAR).EQ.-1.) GOTO 8 
      M1=IABS(MIN1(A3-A2+B1,A3-A1-B2,0.)) 
      M2=MIN1(A1+A2-A3,A1-B1,A2+B2) 
      IF(M2.LT.M1) GOTO 8 
      M1=M1+1 
      M2=M2+1 
      S=0.
      DO 10 I=M1,M2 
      Y=FLOAT(I-1)
      T=BINOM(A3+A1-A2+Y,A1-B1)*BINOM(A3+A2-A1+Y,A2+B2)/BINOM(2.*Y,Y) 
      T=T*BINOM(A1-B1,Y)*BINOM(A2+B2,Y)/BINOM(2.*A3+2.*Y,2.*Y)
      IMIN1=I-1 
10    S=S+PAR(IMIN1)*T*BINOM(A1+A2-A3,Y)*BINOM(2.*A3+2.*Y,A3+A1-A2+Y) 
      T=BINOM(A1+A2+A3,2.*A3)/(BINOM(A1+A2+A3,2.*A1)*BINOM(A1+A2+A3,2.
     1*A2)*(A1+A2+A3+1.)) 
      T=SQRT(T)/SQRT(BINOM(2.*A1,A1+B1)*BINOM(2.*A2,A2+B2)*BINOM(2.*A3
     1,A3+B3))
      NPAR=IFIX(A1-A2-B3) 
      THREEJ=PAR(NPAR)*T*S
      RETURN
8     THREEJ=0. 
      RETURN
      END 
C
      FUNCTION SIXJ(A1,A2,A3,B1,B2,B3)
C
C	SIX-J SYMBOL
C
      D(A,B,C)=1./SQRT(BINOM(2.*A,A+B-C)*BINOM(A+B+C,2.*A)*(A+B+C+1.))
      IF(TR(A1,A2,A3).LT.0..OR.TR(B1,B2,A3).LT.0..OR.TR(A1,B2,B3).LT.0
     1..OR.TR(B1,A2,B3).LT.0.) GOTO 9 
      M1=IABS(MIN1(-A1-B1+A3+B3,-A2-B2+A3+B3,0.)) 
      M2=MIN1(A1+A2+B1+B2+1.,A1+A2-A3,B1+B2-A3,A1+B2-B3,B1+A2-B3) 
      IF(M2.LT.M1) GOTO 9 
      M1=M1+1 
      M2=M2+1 
      S=0.
      DO 10 I=M1,M2 
      Y=FLOAT(I-1)
      T=(BINOM(A1+A2-A3,Y)*BINOM(B1+B2-A3,Y)/BINOM(A1+B1+A2+B2+2.*
     1Y+1.,3.*Y)) 
      T=T*(BINOM(A1+B2-B3,Y)*BINOM(B1+A2-B3,Y)/BINOM(3.*Y,Y)) 
      T=T*(BINOM(A2-B1+B3+Y,A1+A2-A3)*BINOM(B1-A2+B3+Y,B1+B2-A3)/BINO 
     1M(2.*Y,Y))
      T=T*BINOM(2.*B3+2.*Y,A2-B1+B3+Y)*BINOM(A1+B1+A2+B2-2.*B3,A1+B2- 
     1B3)*BINOM(A1+B1+A2+B2+2.*Y,2.*B3+2.*Y)*(A1+B1+A2+B2+2.*Y+1.)
      NPAR=IFIX(Y+A1+A2+B1+B2)
10    S=S+PAR(NPAR)*T 
      T=D(A1,A2,A3)*S 
      T=T*D(A1,B2,B3) 
      T=T*D(B1,A2,B3) 
      SIXJ=T*D(B1,B2,A3)
      RETURN
9     SIXJ=0. 
      RETURN
      END 
C
      FUNCTION WNINJ(A1,A2,A3,B1,B2,B3,C1,C2,C3)
C
C	NINE-J SYMBOL
C
      X1=AMAX1(ABS(A1-C3),ABS(B1-C2),ABS(A2-B3))
      X2=AMIN1(A1+C3,B1+C2,A2+B3) 
      IF(X2.LT.X1) GOTO 9 
      M1=X1+1.
      M2=X2+1.
      WNINJ=0.
      IF(FLOAT(M1).LT.X1+1.) GOTO 6 
      DO 10 I=M1,M2 
      AI=I-1
      T=SIXJ(A1,B1,C1,C2,C3,AI)*SIXJ(A2,B2,C2,B1,AI,B3)*SIXJ(A3,B3,C3,
     1AI,A1,A2) 
      NPAR=2.*AI
      T=PAR(NPAR)*(2.*AI+1.)*T
10    WNINJ=WNINJ+T 
      RETURN
6     DO 11 I=M1,M2 
      AI=FLOAT(I)-.5
      T=SIXJ(A1,B1,C1,C2,C3,AI)*SIXJ(A2,B2,C2,B1,AI,B3)*SIXJ(A3,B3,C3,
     1AI,A1,A2) 
      NPAR=2.*AI
      T=PAR(NPAR)*(2.*AI+1.)*T
11    WNINJ=WNINJ+T 
      RETURN
9     WNINJ=0.
      RETURN
      END 
C
      FUNCTION CLEBSCH(A1,B1,A2,B2,A3,B3)
C	
C     CLEBSCH-GORDAN COEFFICIENT
C
      NPAR=A1-A2+B3
      TEMP=SQRT(2.*A3+1.)
      CLEBSCH=PAR(NPAR)*TEMP*THREEJ(A1,A2,A3,B1,B2,-B3) 
      RETURN
      END
C
      FUNCTION RACAH(A1,A2,B2,B1,A3,B3)
C
C     RACAH COEFFICIENT
C
      NPAR=A1+A2+B2+B1
      RACAH=PAR(NPAR)*SIXJ(A1,A2,A3,B1,B2,B3)
      RETURN
      END
C 
      SUBROUTINE DFUNC(A,B,C,J,M,MPRIME,DRE,DIM)
C
C     CALCULATE THE ROTATION MATRICES (CAPITAL-) DJ-M,MPRIME IN THE
C     SIGN CONVENTION OF ALDER AND WINTHER.
C
      REAL J,M,MPRIME
      ARAD=A/57.295779
      CRAD=C/57.295779
      ARG=M*ARAD+MPRIME*CRAD
      CS=COS(ARG)
      SN=SIN(ARG)
      HV=DJMM(B,J,M,MPRIME)
      DRE=CS*HV
      DIM=SN*HV
      RETURN
      END
C
      SUBROUTINE YLM(L,M,THETA,PHI,YLMRE,YLMIM)
C
C     CALCULATE THE SPHERICAL HARMONIC
C
      FL=L
      FM=M
      HV=SQRT((2.*FL+1.)/(4.*3.1415926))
      CALL DFUNC(PHI,THETA,0.,FL,FM,0.,DRE,DIM)
      YLMRE=HV*DRE
      YLMIM=HV*DIM
      RETURN
      END
C
      FUNCTION PLEG(K,THETA)
C
C     LEGENDRE POLINOMIAL
C
      FK=K
      HV=SQRT((4.*3.1415926)/(2.*FK+1.))
      CALL YLM(K,0,THETA,0.,TRE,TRI)
      PLEG=HV*TRE
      RETURN
      END
C
      FUNCTION DJMM(BETA,J,M,MPRIME)
C
C     CALCULATE THE (SMALL-) D FUNCTION FROM EDMONDS EQ.(4.1.15).
C     THIS QUANTITY IS DENOTED DJ-MPRIME,M BY EDMONDS AND AS DJ-M,MPRIME
C     BY ALDER AND WINTHER.
C
      REAL J,M,MPRIME
      DJMM=0.
      JPMP=J+MPRIME+0.01
      JMMP=J-MPRIME+0.01
      JPM=J+M+.01
      JMM=J-M+.01
      IF((JPMP.LT.0).OR.(JMMP.LT.0).OR.(JPM.LT.0).OR.(JMM.LT.0)) GOTO 11
	EPS=0.000000001
	AB=ABS(BETA)
	IF(AB.GT.EPS) GOTO 20
	IF(M.EQ.MPRIME) THEN
	DJMM=1.
	GOTO 11
	ELSE
	DJMM=0.
	GOTO 11
	END IF
20    F1=FAC(JPMP)*FAC(JMMP)/(FAC(JPM)*FAC(JMM))
      ROOT=SQRT(F1)
      BRAD=BETA/57.295779
      CB=COS(BRAD/2.)
      SB=SIN(BRAD/2.)
      JJ=J+J+.01
      EMMP=M+MPRIME
      IF(EMMP) 12,13,14
12    MMP=EMMP-.01
      GOTO 15
13    MMP=0
      GOTO 15
14    MMP=EMMP+.01
15    CONTINUE
      ISMIN=MAX0(0,-MMP)
      ISMAX=MIN0(JMM,JMMP)
      ISMIN=ISMIN+1
      ISMAX=ISMAX+1
      SUM=0.
      DO 10 ISP1=ISMIN,ISMAX
      IS=ISP1-1
      RJPM=JPM
      RJMM=JMM
      JMPS=JMMP-IS
      RJMPS=JMPS
      RS=IS
      HV=BINOM(RJPM,RJMPS)*BINOM(RJMM,RS)*PAR(JMPS)
      HV=HV*(CB**(2*IS+MMP))*(SB**(JJ-2*IS-MMP))
      SUM=SUM+HV
10    CONTINUE
      DJMM=ROOT*SUM
11    RETURN
      END
C
      FUNCTION FCOEFF(K,L,LPRIME,FJF,FJI)
C
C     F-COEFFICIENT. SEE S.R. DE GROOT E.A. IN SIEGBAHN VOL.2, P. 1206
C
      NPAR=LPRIME-K-1
      FK=K
      FL=L
      FLPR=LPRIME
      HV=SQRT((2.*FL+1.)*(2.*FLPR+1.)*(2.*FJI+1.))
      CL=CLEBSCH(FL,1.,FLPR,-1.,FK,0.)
      FCOEFF=PAR(NPAR)*HV*CL*RACAH(FJF,FJI,FL,FK,FLPR,FJI)
      RETURN
      END
C
	FUNCTION REDMEYL(FL2,FL1,LAMBDA)
C
C	REDUCED MATRIX ELEMENT <L2//YsubLAMBDA//L1>. EDMONDS EQ. 5.4.5
C
	L2=FL2
	L1=FL1
	FL=LAMBDA
	PI=3.1415926
	TEMP=PAR(L2)*SQRT((2.*FL1+1.)*(2.*FL+1.)*(2.*FL2+1)/(4.*PI))
	REDMEYL=TEMP*THREEJ(FL2,FL,FL1,0.,0.,0.)
	RETURN
	END
C
	FUNCTION YBAR(FL2,FJ2,FL1,FJ1,LAMBDA)
C
C	REDUCED MATRIX ELEMENT <L2,1/2,J2//YsubLAMBDA//L1,1/2,J1>
C	SEE EDMONDS EQ. 7.1.7
C
	L2=FL2
	L1=FL1
	FL=LAMBDA
	N=FL2+0.5+FJ1+FL
	TEMP=PAR(N)*SQRT((2.*FJ1+1.)*(2.*FJ2+1.))
	YBAR=TEMP*SIXJ(FL2,FJ2,0.5,FJ1,FL1,FL)*REDMEYL(FL2,FL1,LAMBDA)
	RETURN
	END
C
	FUNCTION SYBAR(FL2,FJ2,FL1,FJ1,LAMBDA,J)
C
C	REDUCED M. E. <L2,1/2,J2//(SIGMA*YsubLAMBDA)subJ//L1,1/2,J1>
C	SEE EDMONDS EQ. 7.1.5
C
	L2=FL2
	L1=FL1
	FL=LAMBDA
	FJ=J
	N=1+LAMBDA+J
	TEMP=PAR(N)*SQRT((2.*FJ1+1.)*(2.*FJ+1.)*(2.*FJ2+1.))*SQRT(6.)
	TEMP=TEMP*WNINJ(FL2,FL1,FL,0.5,0.5,1.,FJ2,FJ1,FJ)
	SYBAR=TEMP*REDMEYL(FL2,FL1,LAMBDA)
	RETURN
	END
C
      FUNCTION A(N,L,K)
C
C	COEFFICIENT OF THE HARMONIC OSCILLATOR RADIAL WAVEFUNCTION
C	POWER EXPANSION......
C
      NL1=N+L+1
      KL1=K+L+1
      A=(PAR(K)/FAC(K))
      A=A*SQRT((2.*FAC(N))/GAMH(NL1))
      NMK=N-K
      A=A*GAMH(NL1)/(FAC(NMK)*GAMH(KL1))
      RETURN
      END
C
	FUNCTION BROMOS(N2,L2,N1,L1,P)
C
C	BRODY-MOSHINSKY COEFFICIENT. REF: MOSHINSKY, THE HARMONIC
C	OSCILLATOR, P.6, EQ. 2.6
C
	NP=P
	FNP=NP
	IF (P.GT.FNP) THEN
C	.........................P HALF-INTEGER.....
	HV=0.5*GAM(NP+2)
	ELSE
C	.........................P INTEGER.....

	HV=0.5*GAMH(NP+1)
	END IF
	TEMP=0.5*FLOAT(L1+L2)
	KMIN=P-TEMP-FLOAT(N2)
	KMIN=MAX(KMIN,0)
	KMAX=P-TEMP
	KMAX=MIN(KMAX,N1)
	B=0.
	KMINP1=KMIN+1
	KMAXP1=KMAX+1
	DO 30 KP1=KMINP1,KMAXP1
	K=KP1-1
	KPRIM=P-TEMP-FLOAT(K)
	B=B+A(N1,L1,K)*A(N2,L2,KPRIM)
30	CONTINUE
	BROMOS=HV*B
	END
C
	FUNCTION TALMI(P,LAMBDA)
C
C	TALMI INTEGRAL OF R**LAMBDA. REF: MOSHINSKY P.6, EQ. 2.9
C
	NA=2.*(P+1.5)
	NB=P+1.5
	IF(PAR(NA).GT.0.) THEN
	HV1=GAM(NB)
	ELSE
	HV1=GAMH(NB)
	ENDIF
	FL=FLOAT(LAMBDA)
	NA=2.*(P+0.5*FL+1.5)
	NB=P+0.5*FL+1.5
	IF(PAR(NA).GT.0.) THEN
	HV2=GAM(NB)
	ELSE
	HV2=GAMH(NB)
	ENDIF
	TALMI=HV2/HV1
	RETURN
	END
C
	FUNCTION RADME(N2,L2,N1,L1,M)
C
C	RADIAL M. E. INTEGRAL [R(N2,L2).R**M.R(N1,L1).R**2.DR]
C
	PMIN=0.5*FLOAT(L1+L2)
	NSTAP=N1+N2+1
	TEMP=0.
	DO 10 I=1,NSTAP
	P=FLOAT(I)-1.+PMIN
	BR=BROMOS(N2,L2,N1,L1,P)
	TA=TALMI(P,M)
	TEMP=TEMP+BROMOS(N2,L2,N1,L1,P)*TALMI(P,M)
10	CONTINUE
	RADME=TEMP
	RETURN
	END
C
	FUNCTION F11(A,B,X)
C	1F1(A,B,X) CONFLUENT HYPERGEOMETRICAL FUNCTION
C
	EPS=0.0001
	TEMP=1.
	CR=1.        
	AR=A-1.
	BR=B-1.
	R=0.
10	CONTINUE
	AR=AR+1.
	BR=BR+1.
	R=R+1.
	CR=((AR*X)/(BR*R))*CR
	AB=ABS(CR)
	IF(AB.LT.EPS) GOTO 20
	TEMP=TEMP+CR
	GOTO 10
20	CONTINUE
	F11=TEMP
	RETURN
	END
C
      FUNCTION BESIH(L,Z)
C    
C     MODIFIED BESSELFUNCTION I OF RANK L+1/2 AND ARGUMENT Z
C	SERIES EXPANSION. SEE GRADSTHTEYN-RYSZIK 8.467
C    
      PI=3.1415926
      SUM1=0.
      SUM2=0.
      HV=EXP(Z)
      L1=L+1
      DO 10 K1=1,L1
      K=K-1
      HV1=FAC(L+K)/(FAC(K)*FAC(L-K)*((2.*Z)**K))
      SUM1=SUM1+HV1*PAR(K)
      SUM2=SUM2+HV1
10    CONTINUE
      BESIH=(1./SQRT(2.*PI*Z))*(HV*SUM1-PAR(L)*SUM2/HV)
      RETURN
      END
      FUNCTION BESKH(L,Z)
C    
C     MODIFIED BESSELFUNCTION K OF RANK L+1/2 AND ARGUMENT Z
C	SERIES EXPANSION. SEE GRADSTHTEYN-RYSZIK 8.468
      PI=3.1415926
      SUM1=0.
      HV=EXP(Z)
      L1=L+1
      DO 10 K1=1,L1
      K=K-1
      HV1=FAC(L+K)/(FAC(K)*FAC(L-K)*((2.*Z)**K))
      SUM1=SUM1+HV1
10    CONTINUE
      BESKH=SQRT(PI/(2.*Z))*(SUM1/HV)
      RETURN
      END
	FUNCTION BESH(L,Z)
C	BESSEL FUNCTION OF HALF-INTEGER RANK (L+1/2)
C	(L.LEQ.0) WITH ARGUMENT Z, VIA RECURSION RELATION
C	zZ_{nu-1}(z) + zZ_{nu+1}(z) = 2zZ_{nu}(z)
C	SEE GRADSTHTEYN-RYSZIK 8.471
C	
	EPS=0.00001
	IF(ABS(Z).LT.EPS) THEN
	  Z=EPS
	ELSE
	  Z=Z
	ENDIF
	PI=3.1415926
	BM1= SQRT(2./(PI*Z))*COS(Z)
	B0=SQRT(2./(PI*Z))*SIN(Z)
	BESH=B0
	IF(L.EQ.0) GOTO 10
	K=0
5	K=K+1
	FK=FLOAT(K)
	BESH=(2.*FK-1.)*B0/Z-BM1
	BM1=B0
	B0=BESH
	IF(K.LT.L) GOTO 5
10	CONTINUE
	RETURN
	END
	FUNCTION BESSPH(L,Z)
C	SPHERICAL BESSEL FUNCTION OF INTEGER RANK L
C	WITH ARGUMENT Z
	PI=3.1415926
	BESSPH=SQRT(PI/(2.*Z))*BESH(L,Z)
	RETURN
	END
