salarioBase = 2400.0

calificacion = float(input("Ingrese su calificacion (0.0, 0.4 o 0.6 o mas): "))

if calificacion == 0.0:
    rendimiento = "Rendimiento inaceptable"
    aumento = salarioBase * calificacion
elif calificacion == 0.4:
    rendimiento = "Desempeno aceptable"
    aumento = salarioBase * calificacion
elif calificacion >= 0.6:
    rendimiento = "Meritorio"
    aumento = salarioBase * calificacion
else:
    rendimiento = "Calificacion invalida"

if rendimiento == "Calificacion invalida":
    print("Error. Ingrese una calificacion valida (0.0, 0.4 o 0.6 o mas)")
else:
    print("Su desempeno fue:", rendimiento)
    print("Su aumento es de: $", aumento)








