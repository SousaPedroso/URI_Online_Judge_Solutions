# -*- coding: utf-8 -*

temp_gasto_hrs = int(input())
vel_media = int(input())
kilomet_total = temp_gasto_hrs * vel_media
litros_necess = kilomet_total / 12
print("%.3f" %litros_necess)