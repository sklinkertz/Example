window.addEventListener ? window.addEventListener("mousemove", showMouseXY, false) : window.attachEvent && window.attachEvent("onmousemove", showMouseXY);

function text3d(x, y) {
  var colors3d = ["#cccccc", "#c9c9c9", "#bbbbbb", "#b9b9b9", "#aaaaaa", "#a9a9a9"];
  var styleStore = "";
  for (var i = 0; i < 6; i++) {
    styleStore += (x * (i * .1)) + "px " + (y * (i * .1)) + "px 0 " + colors3d[i] + ",";
  }
  return styleStore.substr(0, styleStore.length - 1);
}

function shadow3d(x, y) {
  var shadow = ["rgba(0,0,0,.1)", "rgba(0,0,0,.15)", "rgba(0,0,0,.2)", "rgba(0,0,0,.2)", "rgba(0,0,0,.25)", "rgba(0,0,0,.3)"];
  var styleStore = "";
  for (var i = 0; i < 6; i++) {
    styleStore += (x * (i * .01)) + "px " + (y * (i * .01)) + "px " + (i * 2) + "px " + shadow[i] + ",";
  }
  return styleStore.substr(0, styleStore.length - 1);
}

function showMouseXY(event) {
  var target = document.querySelector("header button");
  // Wie 'stark' das Tracking sein soll
  var cX = -(window.innerWidth / 2 - event.clientX) / 90;
  var cY = (window.innerHeight / 2 - event.clientY) / 90;
  target.setAttribute("style", "text-shadow:" + text3d(-(cX), cY) + "," + shadow3d(-(cX), cY) + ";transform:rotateY(" + cX + "deg) rotateX(" + cY + "deg);");
  var radX = (event.clientX > (window.innerWidth * .333333) ? (event.clientX < window.innerWidth * .666666 ? "center" : "right") : "left");
  var radY = (event.clientY > (window.innerHeight * .333333) ? (event.clientY < window.innerHeight * .666666 ? "center" : "bottom") : "top");
  console.log("x: " + cX);
  console.log("y: " + cY);
  console.log("x: " + radX);
  console.log("y: " + radY);

  var bgX = -((event.clientX - window.innerWidth) / window.innerWidth) * 100;
  var bgY = -((event.clientY - window.innerHeight) / window.innerHeight) * 100;
  body.setAttribute("style", "background: radial-gradient(circle at " + bgX + "% " + bgY + "%, #eee 2%, #aaa); background: -webkit-radial-gradient(" + bgX + "% " + bgY + "%,#eee 2%, #aaa);")
  console.log("background: radial-gradient(circle at " + bgX + "% " + bgY + "%, #eee 2%, #aaa; background: -webkit-radial-gradient(" + bgX + "% " + bgY + "%,#eee 2%, #aaa);")

}

var passwords = ['FILM-MAKER', 'WEB_DESIGNER', 'ILLUSTRATOR'];
var indexOld;
var index = Math.floor((Math.random() * passwords.length));
var password = passwords[index];
var characters = [];
var counter = 0;

var interval = setInterval(function() {
  for (i = 0; i < counter; i++) {
    characters[i] = password.charAt(i);
  }
  for (i = counter; i < password.length; i++) {
    characters[i] = Math.random().toString(36).charAt(2);
  }
  $('.password').text(characters.join(''));
}, 25);

function hack() {
  counter++;
  if (counter == password.length) {
    $('.granted, .rerun').removeClass('hidden');
  }
}
$(window).on('keydown', hack);
$('.password').on('click', hack);

$('.rerun').on('click', function() {
  //prevent from displaying the same password two times in a row
  indexOld = index;
  do {
    index = Math.floor((Math.random() * passwords.length));
  } while (index == indexOld);

  $('.granted, .rerun').addClass('hidden');
  password = passwords[index];
  characters = [];
  counter = 0;
});

//keyboard events won't fire if the iframe isn't selected first in Full Page view
$('.start').on('click', function() {
  $(this).addClass('hidden');
  $('.info p:last-child, .password').removeClass('hidden');
});