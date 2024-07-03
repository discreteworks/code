const express = require('express')
const bodyParser = require('body-parser');
const router = express.Router()

router.use( bodyParser.json() );       // to support JSON-encoded bodies

let userData = [{ 'user': '1' }, { 'user': '2' }];

router.get('/', (req, res) => {
  res.json(userData);
})

router.post('/', (req, res) => {
  //console.log(req.body);
  userData[userData.length] = req.body; // add new user
  res.json({'res':true})
})

router.put('/:userId/:newUserId', (req, res) => {
  for (var  i = 0; i < userData.length; i++)
  {
    if (userData[i].user == req.params.userId)
    {
      userData[i].user = req.params.newUserId; // update user id
    }
  }
  res.json({'res':true})
})

router.delete('/:userId', (req, res) => {
  for (var  i = 0; i < userData.length; i++)
  {
    if (userData[i].user == req.params.userId)
    {
      userData.splice(i, 1);   // delete user
      i--; // element is delete and new length is evaluated so decrement i
    }
  }
  res.json({'res':true})
})

module.exports = router
