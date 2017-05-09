      google.charts.load('current', {'packages':['gantt']});
    google.charts.setOnLoadCallback(drawChart);

    function drawChart() {

      var data = new google.visualization.DataTable();
      data.addColumn('string', 'Task ID');
      data.addColumn('string', 'Task Name');
      data.addColumn('string', 'Resource');
      data.addColumn('date', 'Start Date');
      data.addColumn('date', 'End Date');
      data.addColumn('number', 'Duration');
      data.addColumn('number', 'Percent Complete');
      data.addColumn('string', 'Dependencies');

      data.addRows([
        ['planning', 'Project Planning', 'Planning',
         new Date(2017, 0, 9), new Date(2017, 0, 14), null, 100, null],
        ['learning', 'Learning things', 'Learning',
         new Date(2017, 0, 16), new Date(2017, 1, 19), null, 100, null],
        ['materials', 'Get Materials', 'Materials',
         new Date(2017, 0, 16), new Date(2017, 1, 27), null, 100, null],
        ['base', 'Create rotating base', 'Hardware',
         new Date(2017, 1, 6), new Date(2017, 1, 13), null, 100, null],
        ['sensor', 'Set up sensors', 'Hardware',
         new Date(2017, 1, 13), new Date(2017, 1, 20), null, 100, null],
        ['software', 'Software Development', 'Software',
         new Date(2017, 1, 27), new Date(2017, 2, 20), null, 100, null],
        ['arms', 'Setup arms', 'Hardware',
         new Date(2017, 1, 27), new Date(2017, 2, 10), null, 100, null],
        ['mix', 'Calibrate arms with software', 'Ware',
         new Date(2017, 2, 10), new Date(2017, 2, 20), null, 100, null],
        ['piston', 'Making piston', 'Hardware',
         new Date(2017, 2, 16), new Date(2017, 2, 27), null, 100, null],
        ['app', 'Setup Messaging Service', 'Software',
         new Date(2017, 2, 27), new Date(2017, 2, 31), null, 100, null],
        ['testing', 'Testing and Troubleshooting', 'Testing',
         new Date(2017, 2, 31), new Date(2017, 3, 8), null, 100, null],
      ]);

      var options = {
        height: 400,
        gantt: {
          trackHeight: 30
        }
      };

      var chart = new google.visualization.Gantt(document.getElementById('chart_div'));

      chart.draw(data, options);
    }
