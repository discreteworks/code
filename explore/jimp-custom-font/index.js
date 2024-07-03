let Jimp = require("jimp");

let template_name = 'template.png'; // image file to edit.
let fnt_sans_serif_18 = "fonts/sans-serif-18.fnt";
let filename = "output.png";
Jimp.read(template_name, (err, template) => {
  if (err) throw err;
      Jimp.loadFont(fnt_sans_serif_18).then((font) => {
  template
    .print(font, 50, 100, "Hello world")
    .write(filename); // save
  });
});

