//Rotação simples
void RSE ( No ** ppRaiz ) {
    No * pAux ;
    pAux = (* ppRaiz ) -> pDir ;
    (* ppRaiz ) -> pDir = pAux - > pEsq ;
    pAux -> pEsq = (* ppRaiz );
    (* ppRaiz ) = pAux ;
}

void RSD ( No ** ppRaiz ) {
    No * pAux ;
    pAux = (* ppRaiz ) -> pEsq ;
    (* ppRaiz ) -> pEsq = pAux - > pDir ;
    pAux -> pDir = (* ppRaiz );
    (* ppRaiz ) = pAux ;
}