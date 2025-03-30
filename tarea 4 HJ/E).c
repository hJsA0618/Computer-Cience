#include <stdio.h>

void verificar_requisitos() {
    int pasaporte_viejo, pasaporte_consular, robo_perdida_destruccion;
    int mutilacion_deterioro, error_modificacion_dato, discapacidad;

    // Preguntar al usuario sobre el estado de su pasaporte
    printf("El pasaporte fue expedido antes de 1995? (1 para si, 0 para no): ");
    scanf("%d", &pasaporte_viejo);

    printf("El pasaporte fue expedido en alguna Oficina Consular de Mexico? (1 para si, 0 para no): ");
    scanf("%d", &pasaporte_consular);

    printf("El pasaporte se ha robado, perdido o destruido? (1 para si, 0 para no): ");
    scanf("%d", &robo_perdida_destruccion);

    printf("El pasaporte esta mutilado o deteriorado? (1 para si, 0 para no): ");
    scanf("%d", &mutilacion_deterioro);

    printf("Necesita corregir algun dato personal en el pasaporte? (1 para si, 0 para no): ");
    scanf("%d", &error_modificacion_dato);

    printf("Es una persona con discapacidad que no puede manifestar su voluntad? (1 para si, 0 para no): ");
    scanf("%d", &discapacidad);

    // Mostrar mensajes segun las respuestas del usuario
    if (pasaporte_viejo || pasaporte_consular || robo_perdida_destruccion || mutilacion_deterioro || error_modificacion_dato) {
        if (pasaporte_viejo || pasaporte_consular || robo_perdida_destruccion || mutilacion_deterioro) {
            printf("Debera acreditar la nacionalidad mexicana e identidad.\n");
        }

        if (robo_perdida_destruccion) {
            printf("En caso de robo, perdida o destruccion del pasaporte:\n");
            printf(" - Si ocurrio en el territorio nacional, debera levantar un acta ante el Ministerio Publico o autoridad competente y comunicar inmediatamente a la Secretaria, bajo protesta de decir verdad, el hecho y las circunstancias.\n");
            printf(" - Si ocurrio en el extranjero, debera entregar el acta levantada ante la autoridad competente del pais o ante la oficina consular mexicana.\n");
        }

        if (mutilacion_deterioro) {
            printf("Debera presentar el pasaporte y entregar copia certificada de los documentos que comprueben la circunstancia.\n");
        }

        if (error_modificacion_dato) {
            printf("Debera entregar copia certificada de los documentos que comprueben el error o modificacion.\n");
        }
    }

    if (discapacidad) {
        printf("La persona con discapacidad que no pueda manifestar su voluntad debera acudir personalmente en compania de una persona que le asista durante el tramite ante cualquier Delegacion de la SRE u Oficina de Enlace con la SRE con cita previa.\n");
    }

    printf("Recuerde que el pasaporte debe entregarse a la Delegacion o Oficina de Enlace con la SRE durante el proceso del tramite.\n");
    printf("No olvide entregar el comprobante del pago de derechos.\n");
}

int main(void) {
    verificar_requisitos();
    return 0;
}
