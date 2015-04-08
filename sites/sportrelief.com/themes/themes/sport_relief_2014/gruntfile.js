module.exports = function(grunt) {

  // Project configuration.
  grunt.initConfig({
    pkg: grunt.file.readJSON('package.json'),
    jshint: {
      options: {
        jshintrc: '.jshintrc',
        reporter: require('jshint-stylish')
      },
      all: [
        'javascripts/controller.js',
        'javascripts/components/*.js',
      ]
    },
   lesslint: {
      src: ['css/utilities-and-base.less'],
      src: ['css/all-components1.less'],
      src: ['css/all-components2.less'],
      src: ['css/styleguide-and-overrides.less'],
      options: {
        imports: [
          'css/base/**/*.less',
          'css/components/**/*.less',
          'css/utilities/**/*.less'
        ]
      }
    },
    csslint: {
      options: {
        'adjoining-classes': false
      }
    },
    sprite:{
      ideas: {
        src: 'image/components/ideas-pledge/*.png',
        destImg: 'image/components/ideas-pledge/sprite.png',
        destCSS: 'css/utilities/sprites.css'
      }
    },
  });

  // Load the plugins
  grunt.loadNpmTasks('grunt-contrib-jshint');
  grunt.loadNpmTasks('grunt-lesslint');
  grunt.loadNpmTasks('grunt-spritesmith');

  // Default tasks, these run when you type only 'grunt'
  grunt.registerTask('default', ['jshint','lesslint']);

  // 'grunt lint'
  grunt.registerTask('lint', ['jshint','lesslint']);

};
