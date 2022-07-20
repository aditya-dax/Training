from django.http import HttpResponse, HttpResponseRedirect
from django.template import loader
from django.urls import reverse
from .models import Task

def index(request):
    task_temp = Task.objects.all().values()
    template = loader.get_template('index.html')
    context = {
        'task_temp' : task_temp,
    }

    return HttpResponse(template.render(context, request))

def add(request):
    template = loader.get_template('add.html')
    return HttpResponse(template.render({},request))

def addrecord(request):
    temp_title = request.POST['Title']
    temp_description = request.POST['Description']
    temp_status = request.POST['Status']
    new_task = Task(title = temp_title, description = temp_description, status = temp_status)
    new_task.save()
    return HttpResponseRedirect(reverse('index'))

def delete(request, id):
    temp_task = Task.objects.get(id = id)
    temp_task.delete()  
    return HttpResponseRedirect(reverse('index'))

def update(request, id):
    temp_task = Task.objects.get(id = id)
    template = loader.get_template('update.html')
    context = {
    'temp_task': temp_task,
    }
    return HttpResponse(template.render(context, request))

def updaterecord(request, id):
    temp_title = request.POST['Title']
    temp_description = request.POST['Description']
    temp_status = request.POST['Status']
    temp_task = Task.objects.get(id=id)
    temp_task.title = temp_title
    temp_task.description = temp_description
    temp_task.status = temp_status
    temp_task.save()
    return HttpResponseRedirect(reverse('index'))

def change_status(request,id):
    temp_task = Task.objects.filter(id = id)
    if( temp_task[0].status == True ):
        temp_task.update(status=False)
    else:
        temp_task.update(status=True)
    return HttpResponseRedirect(reverse('index'))


