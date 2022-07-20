from django.urls import path
from . import views

urlpatterns = [
    path('', views.index, name='index'),
    path('add/', views.add, name='add'),
    path('add/addrecord/', views.addrecord, name='addrecord'),
    path('delete/<int:id>', views.delete, name='delete'),
    path('update/<int:id>', views.update, name='update'),
    path('change_status/<int:id>', views.change_status, name='change_status'),
    path('update/updaterecord/<int:id>', views.updaterecord, name='updaterecord'),
]