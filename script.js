const display = document.getElementById('display');

function appendNumber(number) {
  display.value += number;
}

function appendOperator(operator) {
  const lastChar = display.value.slice(-1);
  if (display.value !== '' && !['+', '-', '*', '/'].includes(lastChar)) {
    display.value += operator;
  }
}

function appendDot(dot) {
  const parts = display.value.split(/[\+\-\*\/]/);
  const lastPart = parts[parts.length - 1];
  if (!lastPart.includes('.')) {
    display.value += dot;
  }
}

function clearDisplay() {
  display.value = '';
}

function deleteLast() {
  display.value = display.value.slice(0, -1);
}

function calculateResult() {
  try {
    display.value = eval(display.value);
  } catch (e) {
    display.value = 'Error';
  }
}
